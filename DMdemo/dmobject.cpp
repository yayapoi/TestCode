#include "dmobject.h"
#include <QDebug>
#include <QCoreApplication>
#include <QTimer>
#include <QMessageBox>
#include <QProcess>
#include <QLibrary>
#include <atlbase.h>

DmObject::DmObject(QObject *parent)
    : QObject{parent}
{
    initDm();
}

DmObject::~DmObject()
{
    dm->UnBindWindow();
}

typedef   HRESULT (__stdcall *Func) (REFCLSID,REFIID,LPVOID*);
Idmsoft *DmReg(const char* file)
{
    //CoInitialize(0);
    HRESULT  hr;
    Func GetClass=nullptr;
    GetClass=(Func)QLibrary::resolve(file,"DllGetClassObject");
    if(!GetClass)return nullptr;
    IClassFactory* pFactory=nullptr;
    hr=GetClass(_uuidof(Idmsoft),IID_IClassFactory,(LPVOID*)&pFactory);
    if(FAILED(hr))return nullptr;
    Idmsoft* idmsoft=nullptr;
    hr=pFactory->CreateInstance(NULL,_uuidof(Idmsoft),(LPVOID*)&idmsoft);
    pFactory->Release();
    if(!idmsoft)return nullptr;
    return idmsoft;
}

Idmsoft* GetDmObJect()
{
    Idmsoft* m_dm = nullptr;
    //直接加载dll创建对象
    typedef HRESULT(__stdcall* pfnGCO)(REFCLSID, REFIID, void**);
    QString path = QCoreApplication::applicationDirPath()+"/dm.dll";
    HINSTANCE hdllInst = LoadLibrary(path.toStdWString().c_str());
    pfnGCO fnGCO = (pfnGCO)GetProcAddress(hdllInst,"DllGetClassObject");
    if (fnGCO != 0)
    {
        IClassFactory* pcf = nullptr;
        HRESULT hr = (fnGCO)(__uuidof(dmsoft), IID_IClassFactory, (void**)&pcf);
        if (SUCCEEDED(hr) && (pcf != nullptr))
        {
            hr = pcf->CreateInstance(nullptr, __uuidof(Idmsoft), (void**)&m_dm);
            if ((SUCCEEDED(hr) && (m_dm != nullptr))==FALSE)
                return nullptr;
        }
        pcf->Release();
    }
    return m_dm;
}

bool DmObject::initDm()
{
    dm = GetDmObJect();
    if(dm!=nullptr)//初始化COM对象
    {
        qDebug() << QStringLiteral("大漠测试，大漠版本：")<< QString(dm->Ver());
        return true;
    }
    else
    {
        qDebug() << QStringLiteral("大漠插件初始失败，先进行注册");
        return false;
    }
    return false;
}

int DmObject::GetMousePointWindow()
{
    /*dm_ret = dm.GetClientSize(hwnd,screen_w,screen_h);
    dm_ret = dm.SetDict(0,"C:\Documents and Settings\Administrator\桌面\1.txt");
    dm_ret = dm.BindWindow(hwnd,"gdi","normal","normal",0);
    s = dm.Ocr(0,0, screen_w, screen_h,"FEFB01-000000",1.0);*/
    hwnd=dm->GetMousePointWindow();
    //steam dm.BindWindow(hwnd,"normal","normal","normal",0);
    dm->BindWindow(hwnd,"gdi","windows","windows",0);
    return hwnd;
}

int DmObject::screenSize(int &qx, int &qy, int &qw, int &qh)
{
    VARIANT x,y,w,h;
    long backLong=dm->GetWindowRect(hwnd,&x,&y,&w,&h);
    qx=x.intVal;
    qy=y.intVal;
    qw=w.intVal;
    qh=h.intVal;
    return backLong;
}

int DmObject::MoveTo(int x, int y)
{
    return dm->MoveTo(x,y);
}

int DmObject::LeftClick()
{
    return dm->LeftClick();
}

int DmObject::GetColorNum(int x1, int y1, int x2, int y2, const QString &color, double sim)
{
    return dm->GetColorNum(x1, y1, x2, y2, color.toStdWString().c_str(), sim);
}

int DmObject::FindPic(int x1, int y1, int x2, int y2, const QString &pic_name, const QString &delta_color, double sim, int dir, int& x, int& y)
{
    VARIANT qx,qy;
    long backLong=dm->FindPic(x1, y1, x2, y2, (dirStr+pic_name).toStdWString().c_str(), delta_color.toStdWString().c_str(), sim, dir, &qx, &qy);
    x=qx.intVal;
    y=qy.intVal;
    return backLong;
}

int DmObject::FindPicWithoutPath(int x1, int y1, int x2, int y2, const QString &pic_name, const QString &delta_color, double sim, int dir, int& x, int& y)
{
    VARIANT qx,qy;
    long backLong=dm->FindPic(x1, y1, x2, y2, pic_name.toStdWString().c_str(), delta_color.toStdWString().c_str(), sim, dir, &qx, &qy);
    x=qx.intVal;
    y=qy.intVal;
    return backLong;
}

int DmObject::FindPic(int x1, int y1, int x2, int y2, const QString &pic_name, const QString &path, const QString &delta_color, double sim, int dir, int& x, int& y)
{
    VARIANT qx,qy;
    long backLong=dm->FindPic(x1, y1, x2, y2, (path+pic_name).toStdWString().c_str(), delta_color.toStdWString().c_str(), sim, dir, &qx, &qy);
    x=qx.intVal;
    y=qy.intVal;
    return backLong;
}

int DmObject::KeyDown(int vk)
{
    return dm->KeyDown(vk);
}

int DmObject::KeyUp(int vk)
{
    return dm->KeyUp(vk);
}
