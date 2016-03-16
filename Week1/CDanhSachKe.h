#include "CBieuDien.h"
#include "SNode.h"
class CDanhSachKe : public CBieuDien
{
	private:
		int n;
		int m;
	public:
		CMaTranKe();
		~CMaTranKe();
		void ReadInput(char* file);
		void PrintOutput(char* file);
};