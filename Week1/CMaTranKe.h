class CMaTranKe
{
	private:
		int n;
		bool** matrix;
	public:
		CMaTranKe();
		~CMaTranKe();
		ReadInput(char* file);
		PrintOutput(char* file);
};