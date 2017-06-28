## 支持OS X浏览PDF简单视图
运行scheme： `PDFReaderForOSX` 即可


## 支持iOS

pageViewController: pdf翻页效果视图控制器
startingViewController:DataViewController,翻页视图控制器的视图源
modelController:ModelController:NSObject,数据视图数据源的model模型。
```puml
@startuml
object 阅读器
object pageView
object source
object model

阅读器:view
阅读器:事件

pageView:DataSource
source:model
阅读器*--pageView*--source*--model

@enduml
```



