#include "cyber/cyber.h"
#include "cyber/demo_base_proto/student.pb.h"

using apollo::cyber::demo_base_proto::Student;


int main(int argc, char const *argv[])
{
    // 初始化cyber框架
    apollo::cyber::Init(argv[0]);
    // 创建节点
    auto talker_node = apollo::cyber::CreateNode("ergou");
    // 创建发布者
    /*
        std::shared_ptr<apollo::cyber::Writer<MessageT>>
        CreatWriter<MessageT>(const std::_cxx11::string &channel_name)
    */
    auto talker = talker_node->CreateWriter<Student>("chatter");
    // 组织并发布数据
    /*
        循环
        指定频率
    */
    apollo::cyber::Rate rate(0.5);
    uint64_t seq = 0;
    while (apollo::cyber::OK())
    {
        seq++;
        AINFO<<"第"<<seq<<"条数据";
        // 组织数据
        auto stu_ptr = std::make_shared<Student>();
        stu_ptr->set_name("Frank");
        stu_ptr->set_age(seq);
        stu_ptr->set_height(1.4);
        stu_ptr->add_books("Chinese");
        stu_ptr->add_books("Math");
        stu_ptr->add_books("English");
        // 发布数据
        talker->Write(stu_ptr);
        rate.Sleep();
    }
    // 等待节点关闭，释放资源
    apollo::cyber::WaitForShutdown();
    return 0;
}