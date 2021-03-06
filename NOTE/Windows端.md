## Windows端

核心部分包含以下的功能

- 可视化窗口的创建和管理
- 渲染环境的创建和管理
- 事件泵的创建和管理
- 启动Yosef Core
- 在完成所有创建后，在进入while死循环（消息循环）之前
  - 加载初始化脚本包
  - 启动入口脚本

### Layer

```mermaid
graph TD
A[<font size=4>Application layer] --- B[use engine to make specific products, like games, scene render etc]
A ==> C[<font size=4>API layer] --- D[Hide the underlying details and provide API interface]
C ==> E[<font size=4>Logical package layer] --- F[like scene tree]
E ==> G[<font size=4>Functional module layer] --- H[Encapsulate functional modules that have nothing to do with each other]
G ==> L[<font size=4>Platform interface layer]
```





### 窗口的创建

窗口的创建应该包含普通的Win窗口，OpenGL的Win窗口，DirectX的Win窗口

for OpenGL：

Windows上第一次创建的窗口是一个兼容模式的OpenGL环境。为了使OpenGL与运行在Core模式下、所以采用了GDI+绘图的方式去创建（类似Unity）



### 组件的封装

图片按钮，多状态按钮，惊天文字，文件/文件夹选择模块，时间派发基类，基类基类窗口，双缓冲窗口，渲染窗口

### 启动

1. InitCore() :启动内存管理器，包括内存池，初始化管理器，初始化日志模块，初始化Luau虚拟机，初始化物理引擎
2. 创建窗口：框架窗口和视口窗口
3. InitRuntime(): 初始化全局渲染装填，初始化文字引擎，加载内置脚本，初始化内置的材质球，初始化缺省的system FBO
4. StartFromEntry()