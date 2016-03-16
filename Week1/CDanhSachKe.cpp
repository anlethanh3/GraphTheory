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
		ReadInput(char* file);
		PrintOutput(char* file);
};