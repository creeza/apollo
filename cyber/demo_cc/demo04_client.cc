#include "cyber/cyber.h"
#include "cyber/demo_base_proto/addints.pb.h"

using apollo::cyber::demo_base_proto::AddInts_Request;
using apollo::cyber::demo_base_proto::AddInts_Response;

int main(int argc, char const *argv[])
{
    apollo::cyber::Init(argv[0]);
    if (argc != 3)
    {
        AINFO<<"Number of parameters should be 2";
        return 1;
    }
    // 创建客户端节点
    auto client_node = apollo::cyber::CreateNode("client_node");
    // 创建客户端(名称必须与server一致才能正确绑定)
    auto client = client_node->CreateClient<AddInts_Request, AddInts_Response>("addints");
    // 发送请求
    auto req = std::make_shared<AddInts_Request>();
    req->set_num1(atoll(argv[1]));
    req->set_num2(atoll(argv[2]));
    AINFO<<"请求数据 : num1 = "<<req->num1()<<", num2 = "<<req->num2();
    auto response = client->SendRequest(req);
    AINFO<<"响应结果:sum = "<<response->sum();
    apollo::cyber::WaitForShutdown();
    return 0;
}