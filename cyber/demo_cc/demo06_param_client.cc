#include "cyber/cyber.h"
#include "cyber/parameter/parameter_client.h"

using apollo::cyber::ParameterClient;
using apollo::cyber::Parameter;

int main(int argc, char const *argv[])
{
    // 初始化cyber框架
    apollo::cyber::Init(argv[0]);
    // 创建节点
    std::shared_ptr<apollo::cyber::Node> param_client_node = apollo::cyber::CreateNode("client");
    // 创建参数客户端
    auto client = std::make_shared<ParameterClient>(param_client_node, "car_param");

    // client->SetParameter(Parameter("car_type", "apollo"));
    // client->SetParameter(Parameter("height", 1.65));
    // client->SetParameter(Parameter("lasers", 4));

    // 通过参数客户端操作参数
    Parameter temp;
    // 从参数服务端获取参数
    client->GetParameter("type", &temp);
    AINFO<<temp.Name()<<" = "<<temp.AsString();
    client->GetParameter("height", &temp);
    AINFO<<temp.Name()<<" = "<<temp.AsDouble();  
    client->GetParameter("lasers", &temp);
    AINFO<<temp.Name()<<" = "<<temp.AsInt64();
    // 修改参数
    client->SetParameter(Parameter("lasers", 1));
    AINFO<<"修改后...";
    client->GetParameter("lasers", &temp);
    AINFO<<temp.Name()<<" = "<<temp.AsInt64();
    // 
    std::vector<Parameter> ps;
    client->ListParameters(&ps);
    for (auto &&p : ps)
    {
        AINFO<<"参数名称:"<<p.Name()<<";参数类型："<<p.TypeName();
    }
    
    // 等待关闭
    apollo::cyber::WaitForShutdown();
    return 0;
}
