/*************************************************************************
	> File Name: bitmap.h
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2017年10月09日 星期一 20时34分52秒
 ************************************************************************/

#ifndef _BITMAP_H
#define _BITMAP_H

#include<string.h>

class Bitmap final
{
    friend bool operator==(const Bitmap& map1,const Bitmap& map2);

    public:
        explicit Bitmap(int n = 8) : _array(new char[n>>3]),_n(n) {memset(_array,0,_n >> 3);};
        explicit Bitmap(const Bitmap& map) : _array(new char[map._n>>3]),_n(map._n) { *_array = *map._array;};
        
        Bitmap& operator=(const Bitmap& map)
        {
            if(*this == map)
                return *this;

            *_array = *map._array;
            _n = map._n;

            return *this;
        }
        
        ~Bitmap(){delete [] _array;};

        void set(int i) {_array[i>>3] |= (0x80 >> (i & 0x07));};
        void clear(int i) {_array[i>>3] &= ~(0x80 >> (i & 0x07));};
        bool get(int i) const {return (_array[i>>3] & (0x80 >> (i & 0x07)));};
        int size() const {return _n;}

    private:
        char* _array;
        int _n;
};

bool operator==(const Bitmap& map1,const Bitmap& map2)
{
    if(map1._array == map2._array)
        return true;
    return false;
}


#endif
