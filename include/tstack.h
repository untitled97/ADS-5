// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

template<typename T, int size>
class TStack {
class TStack {
private:
    T arr[size];
    int top;
public:
    TStack() :top(-1) {};
    void push(const T& value) {
        if (isFull()) {
        throw std::string("Full!");
            } else {
                arr[++top] = value;
            }
            }
        const T& pop() {
        if (isEmpty()) {
        throw std::string("Empty!");
            } else {
                return arr[top--];
            }
                }
            const T& get() {
        if (isEmpty()) return arr[top];
        else throw std::string("Not get!");
            }
            bool isEmpty()const {
        return top == -1;
        }
            bool isFull()const {
        return top == size - 1;
        }
};

#endif  // INCLUDE_TSTACK_H_
