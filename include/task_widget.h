#ifndef TASK_WIDGET_H
#define TASK_WIDGET_H

#include "qtask.h"

#include "task_box.h"

#include <QWidget>
#include <vector>
#include <map>

class QSpinBox;
class QPushButton;
class QVBoxLayout;
class QHBoxLayout;
class QCheckBox;

class TimeDialog;

class TaskWidget : public QWidget
{
	Q_OBJECT
public:
	TaskWidget( void );
	void load( void );
	~TaskWidget( void );
	void finishChildTask( int id, bool status );
	void chooseChildTask( int id, bool status );
signals:
	void start( void );
	void chooseTask( int id, bool status );
	void finishTask( int id, bool status );
	void workTimeChanged( int minutes );
	void restTimeChanged( int minutes );
public slots:
	void updateTask( const std::vector<QTask> &qtasks );
	void updateTask( QTask qtask );
private slots:
	void doStart( void );
	void hideTask( int state );
	void workTime( int minutes );
	void restTime( int minutes );
private:
	std::vector<TaskBox*> taskGroup;
	QSpinBox* workTimeBox;
	QSpinBox* restTimeBox;
	QPushButton* startButton;
	QVBoxLayout* leftLayout;
	QVBoxLayout* midLayout;
	QHBoxLayout* mainLayout;
	QCheckBox* showFinish;
};

#endif
