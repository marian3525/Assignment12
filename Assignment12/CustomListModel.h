#pragma once
#include <QAbstractListModel>

class CustomListModel : public QAbstractListModel
{
	Q_OBJECT

public:
	CustomListModel(QObject *parent);
};
