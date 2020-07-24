# qt graphics 项目

## 想法
1. 一个跨平台的桌面绘制工具，想法来源于，现在直播特别流行，直播中总是会需要涂涂画画，这个时候就需要一些实用方便的画图工具

## 项目目标
1. 基本画图选项 直线/形状/自由绘画等
2. 支持 - 截图后绘制，
	- 透明背景绘制
	- 支持笔锋

## 进展
07-23
# coreEngine
  这个类主要用来处理 event 事件
# 临时画板
  先将绘画内容，绘制再临时的画板中，

07-24
# drawLine
  QgraphiceObject或者Item都需要添加到scene中才能正常显示
  通过addItem添加到scene中
  之后在engine中添加的item，他们的parent都是engine，通过对象树的关系，也就能正常在scene中显示
