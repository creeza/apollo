#include "cyber/cyber.h"
#include "cyber/demo_base_proto/student.pb.h"

using apollo::cyber::demo_base_proto::Student;

void call_back(const std::shared_ptr<Student>& stu){
    // 解析学生数据，并打印
    AINFO<<"name:"<<stu->name();
    AINFO<<"age:"<<stu->age();
    AINFO<<"height:"<<stu->height();
    for(int i = 0; i < stu->books_size(); ++i){
        AINFO<<"books:"<<stu->books(i);
    }
    AINFO<<"---------------------------------";
}

int main(int argc, char const *argv[])
{
    // 初始化cyber 框架
    apollo::cyber::Init(argv[0]);
    // 创建订阅节点
    auto listener_node = apollo::cyber::CreateNode("cuihua");
    // 创建订阅者
    auto listener = listener_node->CreateReader<Student>("chatter", call_back);
    apollo::cyber::WaitForShutdown();
    return 0;
}
