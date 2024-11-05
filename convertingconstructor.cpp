#include <iostream>
class MyData {
private:
int data;
public:
    MyData(int val) : data(val) {} //prefix explicit

    [[nodiscard]] int get_data() const {
    return data;
   }
};

void print(MyData value) {
   std::cout << "data is " << value.get_data() << std::endl;
}
int main(void)
{
 // Implicitly converts 10 to MyData object via converting constructor
 print(10);

 // Explicit version (add explicit keyword to enforce)
 print(MyData(10));
 return 0;
}
