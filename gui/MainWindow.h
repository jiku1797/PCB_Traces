#include <QMainWindow>

#include <memory>

namespace main_window_details
{
   static constexpr auto width = 500;
   static constexpr auto height = width;
}

class QVBoxLayout;
class QWidget;
class QGraphicsView;
class PCB_scene;
class QPushButton;
class QLabel;

class PCB_MainWindow : public QMainWindow
{
   Q_OBJECT

public:
   PCB_MainWindow();

private:
   void setView();
   void setScene();
   void setResetBtn();
   void handleConnections();
   // -1 = reset, 0 = invalid, 1 = valid
   void setValidityLabel(const int validity);

   QWidget* m_mainWidget;
   QVBoxLayout* m_mainLayout;
   QGraphicsView* m_view;
   QPushButton* m_resetBtn;
   QLabel* m_validSegment;

   PCB_scene* m_scene;
};