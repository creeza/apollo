#include "cyber/cyber.h"
#include "cyber/demo_base_proto/addints.pb.h"

using apollo::cyber::demo_base_proto::AddInts_Request;
using apollo::cyber::demo_base_proto::AddInts_Response;

void call_back(const std::shared_ptr<AddInts_Request>& request, const std::shared_ptr<AddInts_Response>& response){
    // 解析请求数据
    int64_t num1 = request->num1();
    int64_t num2 = request->num2();
    AINFO<<"提交的请求数据:num1 = "<<num1<<", num2 = "<<num2;
    // 求和并响应
    int64_t sum = num1 + num2;
    response->set_sum(sum);
}

int main(int argc, char const *argv[])
{
    // 初始化cyber 框架
    apollo::cyber::Init(argv[0]);
    // 创建service 节点
    auto server_node = apollo::cyber::CreateNode("addIntServer_node");
    // 创建服务端：处理逻辑 + 响应结果
    /*
        模板：
            Request:请求类型
            Response:响应类型
        参数：
            1.serverice_name 主题(话题)
            2.cb:处理请求逻辑的回调函数
    */
    auto server = server_node->CreateService<AddInts_Request, AddInts_Response>("addints", call_back);
    // 等待关闭，释放资源
    apollo::cyber::WaitForShutdown();
    return 0;
}
