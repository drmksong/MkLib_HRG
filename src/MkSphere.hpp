//---------------------------------------------------------------------------
#ifndef MkSphereH
#define MkSphereH
#include <math.h>
#include "MkShape.hpp"
#include "MkPoint.hpp"
// #include "MkTriangle.hpp"

//---------------------------------------------------------------------------
#ifdef __BCPLUSPLUS__
#endif
//---------------------------------------------------------------------------
class MkSphere : public MkShape
{
private:
  // MkTriangles Surf;
  int SurfDivision;
  bool needUpdate;
  bool UpdateSurf();

protected:
  MkPoint FCP;
  double FRadius;
  double FSphereVolume;
  MkPoints FRealPoints;
  virtual void CalcVolume();

public:
  MkSphere();
  MkSphere(double cx, double cy, double cz, double radius);
  MkSphere(MkPoint &cp, double radius);
  MkSphere(MkPoint &&cp, double radius);

  std::string ClassName()
  {
    return std::string("MkSphere");
  }

  void SetSphere(double cx, double cy, double cz, double radius);
  void SetSphere(MkPoint &cp, double radius);
  void SetSphere(MkPoint &&cp, double radius);
#ifdef __BCPLUSPLUS__
  void SetSphere(double cx, double cy, double cz, double radius, TColor C);
  void SetSphere(MkPoint cp, double radius, TColor C);
  void SetSurfDivision(int n) { SurfDivision = n; }
#endif
  virtual void SetCenter(double cx, double cy, double cz);
  virtual void SetCenter(MkPoint &cp);
  virtual void SetCenter(MkPoint &&cp);
  virtual void SetRadius(double radius);


  bool IsInSurface(MkPoint &pnt, double thick);
  bool IsInSurface(MkPoint &&pnt, double thick);
  bool IsInSpace(MkPoint &pnt);
  bool IsInSpace(MkPoint &&pnt);
  bool IsIntersect(MkLine &rl);
  bool IsIntersect(MkLine &&rl);
  bool isSphere() { return true; }

  MkPoints &CalcIntPnts(MkLine &rl);
  MkPoints &CalcIntPnts(MkLine &&rl);
  void GetIntParam(MkLine &rl, double &t1, double &t2);
  void GetIntParam(MkLine &&rl, double &t1, double &t2);

  MkPoint GetCenter();
  double GetRadius();
  double GetVolume();
  MkPoint &operator[](int);
  bool operator==(MkSphere &rs);
  bool operator==(MkSphere &&rs);
  bool operator!=(MkSphere &rs);
  bool operator!=(MkSphere &&rs);
  MkSphere &operator=(MkSphere &rs);
  MkSphere &operator=(MkSphere &&rs);
  bool operator&&(MkLine &rl);
  bool operator&&(MkLine &&rl);
  MkPoints operator&(MkLine &rl);
  MkPoints operator&(MkLine &&rl);

#ifdef __BCPLUSPLUS__
  void Draw(TObject *);
#endif

#if defined(_MSC_VER) && defined(_WINDOWS_)
  void Draw(MkPaint *);
#endif
};

class MkSpheres
{
protected:
  MkSphere *FSphere;
  int FSize;

public:
  MkSpheres(int Size);
  MkSpheres()
  {
    FSize = 0;
    FSphere = NULL;
  }
  ~MkSpheres()
  {
    if (FSphere)
    {
      delete (MkSphere *)FSphere;
      FSphere = NULL;
    }
  }
  void Initialize(int Size);
  void Clear();
  int GetSize() { return FSize; }
  virtual MkSphere &operator[](int);
  MkSpheres &operator=(MkSpheres &spheres);

#ifdef __BCPLUSPLUS__
  void Draw(TObject *);
#endif

#if defined(_MSC_VER) && defined(_WINDOWS_)
  void Draw(MkPaint *);
#endif
};

#endif
