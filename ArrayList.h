template <class T>
class ArrayList {
    private:
        T* data;
        int arrsize;
        int elements;
        void resize();
        bool needtoresize();
    public:
        ArrayList() {
            data = new T[5];
            arrsize = 5;
            elements = 0;
        }
        bool contains(T e);
        int indexof(T e);
        int lastindexof(T e);
        int size();
        T get(int index);
        void set(int index, T e);
        void add(T e);
        void add(int index, T e);
};
