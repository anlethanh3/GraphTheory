#ifndef _CLIST_H_
#define _CLIST_H_

#include "SPoint.h"

class CListPoint
{
	private:
		SPoint* pHead;
		int length;
	public:
		CListPoint();
		~CListPoint();
		
		void 		Add(SPoint* point);
		int 		GetLength();
		int 		GetIndexOf(SPoint* point);
		SPoint*	GetPoint(int index);
};

#endif