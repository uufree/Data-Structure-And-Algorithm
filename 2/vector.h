/*************************************************************************
	> File Name: vector.h
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2017年09月28日 星期四 21时11分57秒
 ************************************************************************/

#ifndef _VECTOR_H
#define _VECTOR_H

#define DEFAULT_SIZE 10

template<typename T>
class Vector
{
    protected:
        int _size;  //规模
        int _capacity;   //容量
        T* _elem;    //数据区

        void copyFrom(T const* array,int low,int hight);
        void expand(); 
        void shrink();
        bool bubble();  //扫描交换
        int max(int low,int hight);
        void bubbleSort();  //冒泡排序
        void selectSort();
        void mergeSort();
        void merge();
        int partition(int low,int hight);
        void quickSort(int low,int hight);
        void heapSort(int low,int hight);
    
    public:
        Vector(int capacity = DEFAULT_SIZE,T elem = 0);
        Vector(T const* array,int size);
        Vector(T const* array,int low,int hight);
        Vector(Vector<T> const& array);
        Vector(Vector<T> const& array,int low,int hight);
        ~Vector();

//只读接口
        int size() const;
        bool empty() const;
        bool isSort() const;
        int find(const T& elem) const;
        int find(const T& elem,int low,int hight) const;

//可写接口
        T& operator[](int rank) const;
        Vector<T>& operator=(const Vector<T>& elem);
        T remove(int rank);
        int remove(int low,int hight);
        int insert(int rank,const T& elem);
        int insert(const T& elem);
        void sort(int low,int hight);
        void sort();
        void unsort();
        void unsort(int low,int hight);
        void deduplicate(); //无序去重
        void uniquify();    //有序去重

        void traverse(void (*)(T&));
        template<typename VST> void traverse(VST&); //函数对象
};





#endif
