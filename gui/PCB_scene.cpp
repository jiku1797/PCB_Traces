#include "PCB_scene.h"

#include <QGraphicsSceneMouseEvent>
#include <QColor>

PCB_scene::PCB_scene(QObject* parent) : QGraphicsScene(parent) 
{ 
   setup();
}

void PCB_scene::setup() 
{ 
   const QRectF sceneRect{0.0, 0.0, 450.0, 430.0};   
   setSceneRect(sceneRect); 
}

void PCB_scene::mousePressEvent(QGraphicsSceneMouseEvent* event) 
{
   if(event->button() == Qt::LeftButton)
   {
      event->accept();
      handleLeftClick(event);       
   }
   else if(event->button() == Qt::RightButton)
   {
      event->accept();
      handleRightClick();
   }
   else
   {
      event->ignore();
   }  
}

void PCB_scene::handleLeftClick(QGraphicsSceneMouseEvent* event) 
{ 
   const auto newPos = event->scenePos();
   bool validPos = true;
   const PrimitiveTraceTypes::Point pt{newPos.x(), newPos.y()};
   
   if(m_firstClick)
   {
      m_prevPoint = newPos;  
      m_firstClick = false; 
      m_controller.addSegment(pt);
      emit isValid(-1);
   }
   else
   {
      if(m_controller.addSegment(pt))
      {
         paintLine(m_prevPoint, newPos);
         m_prevPoint = newPos;
         emit isValid(1);
      }
      else
      {
         validPos = false;
         emit isValid(0);
      }
   }

   if(validPos)
   {
      paintCircle(newPos);
   }
 
}

void PCB_scene::handleRightClick()
{
   m_firstClick = true;
   m_controller.traceCompleted();
}

void PCB_scene::paintCircle(const QPointF& pt) 
{ 
   namespace psd = pcb_scene_details; 
   const QBrush brush(Qt::black);
   const QPen pen(brush, 2.0, Qt::SolidLine, Qt::RoundCap);    
   addEllipse(pt.x(), pt.y(), psd::radius, psd::radius, pen);
}

void PCB_scene::paintLine(const QPointF& from, const QPointF& to)
{
   const QBrush brush(Qt::blue);
   const QPen pen(brush, 2.0, Qt::SolidLine, Qt::RoundCap);
   addLine(from.x(), from.y(), to.x(), to.y(), pen);
}

void PCB_scene::handleReset(bool clicked) 
{ 
   // reset validity of last segment
   emit isValid(-1);
   
   // clear scene
   clear();   

   // reset controller
   m_controller.reset();
}
