# C++设计模式

## 如何解决复杂性？

+ 分解
  + 人们面对复杂性有一个常见的做法：即分而治之，将大问题分解为多个小问题，将复杂问题分解为多个简单问题。
+ 抽象
  + 更高层次来讲，人们处理复杂性有一个通用的技术，即抽象。由于不能掌握全部的复杂对象，我们选择忽视它的非本质细节，而去处理泛化和理想化了的对象模型。
  
  
## 面向对象设计原则

1. 依赖倒置原则（DIP）

  + 高层模块(稳定)不应该依赖于低层模块(变化)，二者都应该依赖于抽象(稳定) 。
  + 抽象(稳定)不应该依赖于实现细节(变化) ，实现细节应该依赖于抽象(稳定)。
  
2. 开放封闭原则（OCP）

  + 对扩展开放，对更改封闭。
  + 类模块应该是可扩展的，但是不可修改。
  
3. 单一职责原则（SRP）

  + 一个类应该仅有一个引起它变化的原因。
  + 变化的方向隐含着类的责任。
  
4. Liskov 替换原则（LSP）

  + 子类必须能够替换它们的基类(IS-A)。
  + 继承表达类型抽象。
  
5. 接口隔离原则（ISP）

  + 不应该强迫客户程序依赖它们不用的方法。
  + 接口应该小而完备。
  
6. 优先使用对象组合，而不是类继承

  + 类继承通常为“白箱复用”，对象组合通常为“黑箱复用” 。
  + 继承在某种程度上破坏了封装性，子类父类耦合度高。
  + 而对象组合则只要求被组合的对象具有良好定义的接口，耦合度低。
  
7. 封装变化点

  + 使用封装来创建对象之间的分界层，让设计者可以在分界层的一侧进行修改，而不会对另一侧产生不良的影响，从而实现层次间的松耦合。
  
8. 针对接口编程，而不是针对实现编程

  + 不将变量类型声明为某个特定的具体类，而是声明为某个接口。
  + 客户程序无需获知对象的具体类型，只需要知道对象所具有的接口。
  + 减少系统中各部分的依赖关系，从而实现“高内聚、松耦合”的类型设计方案。

## 从封装变化角度对模式分类

### 组件协作：

+ [Template Method](Template Method/README.md)
+ [Template-Pattern(Head-First版)](Template-Pattern/README.md)
+ [Observer/Event](Observer/README.md)
+ [Observer(Head-First版)](Observer-Pattern/README.md)
+ [Strategy](Strategy/README.md)
+ [Strategy(Head-First版)](Strategy-Pattern/README.md)

### 单一职责：

+ [Decorator](Decorator/README.md)
+ [Decorator(Head-First版)](Decorator-Pattern/README.md)
+ [Bridge](Bridge/README.md)

### 对象创建:

+ [Factory Method](Factory Method/README.md)
+ [Factory(Head-First版)](Factory-Pattern/README.md)
+ [Bridge](Bridge/README.md)
+ [Abstract Factory](Abstract Factory/README.md)
+ [Prototype](Prototype/README.md)
+ [Builder](Builder/README.md)

### 对象性能：

+ [Singleton](Singleton/README.md)
+ [Flyweight(享元模式)](Flyweight/README.md)

### 接口隔离:

+ [Façade(门面模式)](Facade/README.md)
+ [Proxy](Proxy/README.md)
+ [Mediator(中介者)](Mediator/README.md)
+ [Adapter](Adapter/README.md)

### 状态变化：

+ [Memento(备忘录)](Memento/README.md)
+ [State](State/README.md)

### 数据结构：

+ [Composite(组合模式)](Composite/README.md)
+ [Iterator](Iterator/README.md)
+ [Chain of Resposibility(职责链)](Chain of Resposibility/README.md)

### 行为变化：

+ [Command](Command/README.md)
+ [Command(Head-First版)](Command-Pattern/README.md)
+ [Visitor](Visitor/README.md)

### 领域问题：

+ [Interpreter](Interpreter/README.md)

## 总结

### 现代较少用的模式

+ Builder
+ Mediator
+ Memento
+ Iterator
+ Chain of Resposibility
+ Command
+ Visitor
+ Interpreter
