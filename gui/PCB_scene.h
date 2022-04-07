#ifndef PCB_SCENE_H
#define PCB_SCENE_H

#include <QGraphicsScene>

#include "TraceController.h"

namespace pcb_scene_details
{
   static constexpr auto radius = 4.0;	
}

class PCB_scene : public QGraphicsScene
{
   Q_OBJECT

public:
   PCB_scene(QObject* parent = nullptr);

   void setup();

public slots:
   void handleReset(bool clicked);

signals:
   // -1 = reset, 0 = invalid, 1 = valid
   void isValid(int valid);

private:
   void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
   void handleLeftClick(QGraphicsSceneMouseEvent* event);
   void handleRightClick();
   void paintCircle(const QPointF& pt);
   void paintLine(const QPointF& from, const QPointF& to);

   TraceController m_controller;
   QPointF m_prevPoint;
   bool m_firstClick{true};
};

#endif // !PCB_SCENE_H