#include "MainWindow.h"

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGraphicsView>
#include <QLabel>
#include <QPushButton>

#include "PCB_scene.h"

PCB_MainWindow::PCB_MainWindow() 
   : m_mainWidget{new QWidget(this)}
{ 
   setFixedHeight(main_window_details::height); 
   setFixedWidth(main_window_details::height);
   setWindowTitle("PCB Traces designer");
   
   m_mainLayout = new QVBoxLayout(m_mainWidget);
   setCentralWidget(m_mainWidget);  
   QLabel* instruction = new QLabel("Left-click to add points. Right-click to finish trace", 
      m_mainWidget);
   QHBoxLayout* topLayout = new QHBoxLayout(nullptr);
   topLayout->addWidget(instruction);
   setResetBtn();
   topLayout->addWidget(m_resetBtn);
   m_mainLayout->addLayout(topLayout);      
   m_validSegment = new QLabel(m_mainWidget);
   m_mainLayout->addWidget(m_validSegment);
   
   setView();

   handleConnections();
}

void PCB_MainWindow::setView() 
{ 
   m_view = new QGraphicsView(m_mainWidget);
   m_view->setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
   setScene();
   m_mainLayout->addWidget(m_view);
   m_view->show();
}

void PCB_MainWindow::setScene() 
{
   m_scene = new PCB_scene(m_view);   
   m_view->setScene(m_scene);
}

void PCB_MainWindow::setResetBtn() 
{ 
   m_resetBtn = new QPushButton("Reset", m_mainWidget); 
   QObject::connect(m_resetBtn, &QPushButton::clicked, 
      [this](bool clicked) { m_scene->handleReset(clicked); });
}

void PCB_MainWindow::handleConnections()
{
   QObject::connect(m_scene, &PCB_scene::isValid, 
      [this](int valid){setValidityLabel(valid);});
}

void PCB_MainWindow::setValidityLabel(const int validity)
{
   QString validTxt{};
   switch(validity)
   {
      case -1:
         validTxt = "";
         break;
      case 0:
         validTxt = "INVALID SEGMENT";
         break;
      case 1:
         validTxt = "VALID SEGMENT";
         break;
      default:
         validTxt = "ERROR";
   }

   m_validSegment->setText(validTxt);
}
