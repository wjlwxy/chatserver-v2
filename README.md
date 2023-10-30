#chatserver

可以工作在 nginx tcp 负载均衡环境中的集群聊天服务器和客户端源码 基于 muduo,nginx,redis 实现 添加了数据库连接池提高了并发能力，并且降低了聊天延迟

编译方式：

一键编译：

./csbuild

or

自行指令:

cd build

rm -rf \*

cmake ..

make

运行：

服务器：
./bin/ChatServer 127.0.0.1 6000 （后面的 ip 和 port 可以自己设置，需要在 nginx 中的配置文件中修改或添加， 服务端可以有多个，每个都有一个自己的 ip 和 port)

客户端：
./bin/ChatClient 127.0.0.1 8000 (所有客户端需要统一连接一个 ip 和 port，需要在 nginx 中的配置文件中修改或添加)

依赖：

nginx muduo boost redis gcc mysql  json
