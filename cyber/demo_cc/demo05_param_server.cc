/*
    参数服务端设置数据(服务端也可以操作数据)，客户端操作数据
*/
#include "cyber/cyber.h"
#include "cyber/parameter/parameter_server.h"

using apollo::cyber::ParameterServer;
using apollo::cyber::Parameter;

int main(int argc, char const *argv[])
{
    apollo::cyber::Init(argv[0]);
    // 创建节点
    std::shared_ptr<apollo::cyber::Node> server_node = apollo::cyber::CreateNode("car_param");
    // 创建参数服务端
    auto server = std::make_shared<ParameterServer>(server_node);
    // 操作参数

    //1. 增添数据
    server->SetParameter(Parameter("car_type", "apollo"));
    server->SetParameter(Parameter("height", 1.65));
    server->SetParameter(Parameter("lasers", 4));

    //2. 查询参数
    // a.获取某个指定参数
    Parameter temp;
    server->GetParameter("car_type", &temp);
    AINFO<<temp.Name()<<" == "<<temp.AsString();
    server->GetParameter("height", &temp);
    AINFO<<temp.Name()<<" == "<<temp.AsDouble();
    server->GetParameter("lasers", &temp);
    AINFO<<temp.Name()<<" == "<<temp.AsInt64();   
    // b.获取所有参数
    std::vector<Parameter> ps;
    server->ListParameters(&ps);
    for (auto &&p : ps)
    {
        // p.DebugString()将整个参数的键值对以字符串方式输出
        AINFO<<p.Name()<<"------"<<p.TypeName()<<"------"<<p.DebugString();
    }

    // 3.修改参数(API和设置参数一样)
    server->SetParameter(Parameter("lasers", 100));
    server->GetParameter("lasers", &temp);
    AINFO<<temp.Name()<<" == "<<temp.AsInt64();  

    apollo::cyber::WaitForShutdown();
    return 0;
}
