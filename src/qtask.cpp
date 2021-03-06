#include "qtask.h"

QTask::QTask( void ) : BasicTask( 0, 0, 1, false, false )
{
	;
}

QTask::QTask( Task task ) : BasicTask( task )
{
	tag = QString::fromStdWString(task.tag);
	name = QString::fromStdWString(task.name);
}

Task QTask::toTask( void )
{
	Task task(*this);
	
	task.tag = tag.toStdWString();
	task.name = name.toStdWString();

	return task;
}

QTaskData::QTaskData( TaskData taskData ) : BasicTaskData( taskData )
{
	tag = QString::fromStdWString( taskData.tag );
}

TaskData QTaskData::toTaskData( void )
{
	TaskData taskData(*this);
	taskData.tag = tag.toStdWString();
	
	return taskData;
}
