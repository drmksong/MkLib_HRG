//---------------------------------------------------------------------------
#ifndef MkCubeH
#define MkCubeH
//---------------------------------------------------------------------------
#include "MkPoint.hpp"
#include "MkShape.hpp"

class MkCube : public MkShape
{
protected:
  MkPoint FCenter;
  double Psi, Theta; // degree
  double XLength;
  double YLength;
  double ZLength;

public:
  MkCube();
  MkCube(MkPoint &rp);
#ifdef __BCPLUSPLUS__
  AnsiString ClassName()
  {
    return AnsiString("MkCube");
  };
#else
  std::string ClassName()
  {
    return std::string("MkCube");
  };
#endif
  void SetCenter(MkPoint &center)
  {
    FCenter = center;
  };

  void SetCenter(MkPoint &&center)
  {
    FCenter = center;
  };
  
  void SetRotation(double psi, double theta)
  {
    Psi = psi;
    Theta = theta;
  }
  void SetLength(double xl, double yl, double zl)
  {
    XLength = xl;
    YLength = yl;
    ZLength = zl;
  }
  void SetXLength(double xl) { XLength = xl; }
  void SetYLength(double yl) { YLength = yl; }
  void SetZLength(double zl) { ZLength = zl; }

public:
  double GetNorm(MkPoint &rp);
  double GetNorm(MkPoint &&rp);
  MkPoint &GetNormPoint(MkPoint &rp);
  MkPoint &GetNormPoint(MkPoint &&rp);
  double GetXLength() { return XLength; }
  double GetYLength() { return YLength; }
  double GetZLength() { return ZLength; }

public:
  bool IsInSurface(MkPoint &pnt, double thick);
  bool IsInSurface(MkPoint &&pnt, double thick);
  bool IsInSpace(MkPoint &pnt);
  bool IsInSpace(MkPoint &&pnt);
  bool IsIn(MkPoint &pnt);
  bool IsIn(MkPoint &&pnt);
  bool isCube() { return true; }

  MkPoint operator[](int i);
  MkCube &operator=(MkCube &rc)
  {
    FCenter = rc.FCenter;
    Psi = rc.Psi;
    Theta = rc.Theta;
    XLength = rc.XLength;
    YLength = rc.YLength;
    ZLength = rc.ZLength;
    return (*this);
  }
  bool operator==(MkCube &rc);
  bool operator!=(MkCube &rc);

#ifdef __BCPLUSPLUS__
  void Draw(TObject *);
#endif

#if defined(_MSC_VER) && defined(_WINDOWS_)
  void Draw(MkPaint *);
#endif
};

class MkCubes
{
private:
  int FSize;
  MkCube *FCube;

public:
  MkCubes();
  MkCubes(int);
  ~MkCubes();
  bool Initialize(int size);
  bool Initialize(int size, MkCube *fault);
  void Clear();

  MkCube &operator()(int);
  MkCube &operator[](int);
  MkCubes &operator=(MkCubes &a);

  int GetSize() { return FSize; };

#ifdef __BCPLUSPLUS__
  void Draw(TObject *);
#endif

#if defined(_MSC_VER) && defined(_WINDOWS_)
  void Draw(MkPaint *);
#endif
};

extern MkCube NullCube;
//---------------------------------------------------------------------------
#endif
