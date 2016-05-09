#include <iostream>
#include <string>
#include <map>
#include <fstream>

class LZW
{
private:
	std::string stringBase;
	int bit;
	int index;
	int max;
	std::map<std::string, int> trieTree;
	std::map<std::string, std::string> trieTreeDecode;
public:
	LZW();
	LZW(std::string base)
	{
		this->stringBase = base;
		this->index = stringBase.length();
		this->bit = MaxBit(this->index);
		this->max = Pow(2, this->bit);
		for (int i = 0; i < this->index; i++)
		{
			std::string k = stringBase.substr(i, 1);
			this->trieTree[k] = i;
			trieTreeDecode[WriteBit(i, bit)] = k;
		}
	}
	~LZW()
	{
		bit = -1;
		index = -1;
		max = -1;
		stringBase.clear();
		trieTree.clear();
		trieTreeDecode.clear();
	}
	std::string Encode(std::string stringEncode)
	{
		int start = 0;
		int next = -1;
		int len = stringEncode.length();
		std::string result = "";
		while (start < len)
		{
			int next = start + 1;
			std::string str = "";
			while ((str = stringEncode.substr(start, next - start + 1)) != "" && trieTree[str] != 0)
			{
				next++;
			}
			result += WriteBit(trieTree[str.substr(0, str.length() - 1)], this->bit);

			trieTree[str] = this->index;
			start = next;
			if (this->index >= this->max)
			{
				this->bit++;
				this->max = Pow(2, this->bit);
			}
			this->index++;
		}
		return result;
	}
	std::string Decode(std::string stringDecode)
	{
		std::string result = "";
		int start = 0;
		int len = stringDecode.length();
		std::string strPrevious = "";
		while (start < len)
		{
			std::string strBit = stringDecode.substr(start, this->bit);
			start += bit;
			std::string strCurrent;
			while ((strCurrent = trieTreeDecode[strBit]) == "")
			{
				strBit = strBit.substr(1);
			}
			if (strCurrent != "#" && trieTree[strPrevious + strCurrent.substr(0,1)] == 0)
			{
				trieTree[strPrevious + strCurrent.substr(0, 1)] = index;
				trieTreeDecode[WriteBit(index, bit)] = strPrevious + strCurrent.substr(0, 1);
				index++;
				if (this->index >= this->max)
				{
					this->bit++;
					this->max = Pow(2, this->bit);
				}
				strPrevious = strCurrent;
			}
			else
			{
				strPrevious += strCurrent;
				if (strCurrent == "#")
				{
					strPrevious = strCurrent;
				}
			}
			result += strPrevious;
		}
		return result;
	}
private:
	int MaxBit(int value)
	{
		int bit = 1;
		while (value = value >> 1)
		{
			bit++;
		}
		return bit;
	}
	int Pow(int value, int degree)
	{
		if (degree == 0)
			return 1;
		return value * Pow(value, degree - 1);
	}
	std::string WriteBit(int value, int len)
	{
		std::string bit = "";
		bool isTrue = false;
		while (value != 0)
		{
			if (value % 2 == 1)
				bit = "1" + bit;
			else
				bit = "0" + bit;
			value = value / 2;
		}
		int distance = len - bit.length();
		if (distance > 0)
		{
			for (int i = 0; i < distance; i++)
			{
				bit = "0" + bit;
			}
		}
		return bit;
	}
};

int main(int argc, char** argv)
{
	if (argc != 5)
	{
		return 1;
	}
	std::fstream fs;

	fs.open(argv[1], std::iostream::in);
	std::string stringBase;
	fs >> stringBase;
	fs.close();

	fs.open(argv[2], std::iostream::in);
	std::string string;
	fs >> string;
	fs.close();

	LZW* lzw = new LZW(stringBase);
	fs.open(argv[3], std::iostream::out);

	switch (argv[4][0])
	{
	case '0':
		fs << lzw->Encode(string) << std::endl;
		break;
	case '1':
		fs << lzw->Decode(string) << std::endl;
	}

	fs.close();

	delete lzw;

	return 0;
}