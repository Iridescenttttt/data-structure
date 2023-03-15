#include<iostream>
using namespace std;

#define InitSize 10

class SqList {
public:
    int *data;
    int MaxSize;
    int length;

    /**
     * @brief Init the list.
     * 
     */
    void InitList() {
        data = new int[InitSize];
        MaxSize = InitSize;
        length = 0;
    }

    /**
     * @brief Increase the list length.
     * 
     * @param size increase size.
     */
    void IncreaseList(int size) {
        int *p = data;
        data = new int[InitSize + size];
        for(int i = 0; i < length; i++){
            data[i] = p[i];
        }
        MaxSize += size;
        delete []p;
    }

    /**
     * @brief Insert element to list.
     * 
     * @param pos insert position
     * @param e element
     */
    void ListInsert(int pos, int e) {
        if(pos < 1 || pos > length + 1)cout<<"Please input the right postion!"<<endl;
        if(length == MaxSize) IncreaseList(5);
        for(int i = length + 1; i >= pos; i--){
            data[i] = data[i - 1];
        }
        data[pos - 1] = e;
        length++;
    }

    /**
     * @brief Delete the element at the corresponding position.
     * 
     * @param pos position
     * @return int deleted element
     */
    int ListDelete(int pos) {
        if(pos < 1 || pos > length)cout<<"Please input the right postion!"<<endl;
        int ret = data[pos - 1];
        for(int i = pos; i < length; i++){
            data[i - 1] = data[i];
        }
        length--;
        return ret;
    }

    /**
     * @brief Get the Elem object.
     * 
     * @param pos position
     * @return int element
     */
    int GetElem(int pos) {
        if(pos < 1 || pos > length)cout<<"Please input the right postion!"<<endl;
        return data[pos - 1];
    }

    /**
     * @brief Find the element position
     * 
     * @param val value
     * @return int position
     */
    int LocateElem(int val) {
        for(int i = 0; i < length; i++){
            if(data[i] == val)return i;
        }
        return -1;
    }
};


int main() {
    SqList L;
    L.InitList();
    for(int i = 0; i < 10; i++) {
        L.data[i] = i;
        L.length++;
    }
    int e = L.GetElem(1);
    cout<<e<<endl;
    return 0;
}