#ifndef CUSTOMRANGES_HPP
#define CUSTOMRANGES_HPP

#include <QDialog>

#include "wesnothrc.hpp"

namespace Ui {
    class CustomRanges;
}

class CustomRanges : public QDialog {
    Q_OBJECT
public:
	CustomRanges(QWidget *parent, QMap<QString, color_range>& initial_ranges);
    ~CustomRanges();

	const QMap<QString, color_range>& ranges() const {
		return ranges_;
	}

protected:
	void changeEvent(QEvent *e);

	void deserialize_default_range();
	void deserialize_range(const QString& name, const color_range& range);
	void serialize_range(QString& name, color_range& range);

private:
    Ui::CustomRanges *ui;

	QMap<QString, color_range> ranges_;

	bool ignore_serializing_events_;

private slots:
	void on_cmdDelete_clicked();
	void on_cmdAdd_clicked();
	void on_leName_textChanged(QString);
	void on_leMin_textChanged(QString);
	void on_leMax_textChanged(QString);
	void on_leAvg_textChanged(QString);
	void on_cmdUpdate_clicked();
	void on_tbMin_clicked();
	void on_tbMax_clicked();
	void on_tbAvg_clicked();
	void on_rangesList_currentRowChanged(int);
};

#endif // CUSTOMRANGES_HPP
