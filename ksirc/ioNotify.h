#ifndef KIONOTIFY_H
#define KIONOTIFY_H

#include <qobject.h>

#include "messageReceiver.h"

class KSircIONotify : public QObject,
		   public KSircMessageReceiver
{
  Q_OBJECT
public:
  KSircIONotify(KSircProcess *_proc);
  virtual ~KSircIONotify();

  virtual void sirc_receive(QCString, bool broadcast);
  virtual void control_message(int, QString);

  virtual filterRuleList *defaultRules();

signals:
  virtual void notify_online(QString);
  virtual void notify_offline(QString);

protected slots:

private:
  KSircProcess *proc;
};

#endif
