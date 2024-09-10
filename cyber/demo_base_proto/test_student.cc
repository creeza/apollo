#include "cyber/demo_base_proto/student.pb.h"

int main(int argc, char const *argv[])
{
    // 创建对象
    apollo::cyber::demo_base_proto::Student stu;
    // 写数据
    stu.set_name("zhangsan");
    stu.set_age(18);
    stu.set_height(1.75);
    stu.add_books("yuwen");
    stu.add_books("c++");
    stu.add_books("python");

    // 读数据
    std::string name = stu.name();
    uint64_t age = stu.age();
    double height = stu.height();
    std::cout<<"name = "<<name<<", age = "<<age
             <<", height = "<<height
             <<", books = ";
    for(int i = 0; i < stu.books_size(); ++i)
    {
        std::string book = stu.books(i);
        std::cout<<book<<" ";
    }
    std::cout<<std::endl;
    return 0;
}
