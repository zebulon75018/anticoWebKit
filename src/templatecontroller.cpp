/**
  @file
  @author Stefan Frings
*/

#include "templatecontroller.h"
#include "templatecache.h"
#include "template.h"
#include "antico.h"

#include "../qlSysInfo-master/systeminfo.h"

/** Cache for template files */
extern TemplateCache* templateCache;
extern Antico *externa;



TemplateController::TemplateController()
{
}

void TemplateController::service(HttpRequest& request, HttpResponse& response)
{
    response.setHeader("Content-Type", "text/html; charset=ISO-8859-1");
    SystemInfo *si = new SystemInfo();

    Template t=templateCache->getTemplate("index",request.getHeader("Accept-Language"));
    t.enableWarnings();
    t.setVariable("path", si->GetDistroName()/*request.getPath()*/);
     /*
    t.setVariable("cpuarchi","Linux");

    QMap<QByteArray,QByteArray> headers=request.getHeaderMap();
    QMapIterator<QByteArray,QByteArray> iterator(headers);
    t.loop("header",headers.size());
    int i=0;

    QList <QMenu *> menus = externa->get_category_menu()->get_menus();
    foreach(QMenu *m, menus) {
	qDebug()<< m->menuAction()->text();

        t.setVariable(QString("header%1.name").arg(i),QString(i));
        t.setVariable(QString("header%1.value").arg(i), m->menuAction()->text());
        ++i;
	}
    */
/*
    while (iterator.hasNext())
    {
        iterator.next();
        t.setVariable(QString("header%1.name").arg(i),QString(iterator.key()));
        t.setVariable(QString("header%1.value").arg(i),QString(iterator.value()));
        ++i;
    } */

    response.write(t.toLatin1(),true);
}
