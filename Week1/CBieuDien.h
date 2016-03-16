class CBieuDien
{
	private:
		int type;
	public:
		CBieuDien();
		~CBieuDien();
		
		virtual void ReadInput(char* file) = 0;
		virtual void PrintOutput(char* file) = 0;
};