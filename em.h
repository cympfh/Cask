enum em {
  AWA,HAJ,IKA,IYA,KOW,ODO,SUK,TAK,YAS,YOR
};

struct kount {
  int awa,haj,ika,iya,kow,odo,suk,tak,yas,yor;
  kount() {
    awa=haj=ika=iya=kow=odo=suk=tak=yas=yor=0;
  }
};

kount add(const kount&a, const kount&b) {
  kount ret;
  ret.awa = a.awa + b.awa;
  ret.haj = a.haj + b.haj;
  ret.ika = a.ika + b.ika;
  ret.iya = a.iya + b.iya;
  ret.kow = a.kow + b.kow;
  ret.odo = a.odo + b.odo;
  ret.suk = a.suk + b.suk;
  ret.tak = a.tak + b.tak;
  ret.yas = a.yas + b.yas;
  ret.yor = a.yor + b.yor;
  return ret;
}

kount shift(em e) {
  kount ret;
  switch(e) {
    case SUK: ret.iya++; break;
    case IKA: ret.yas++; break;
    case KOW: ret.yas++; break;
    case YAS: ret.ika++; ret.tak++;
              ret.odo++;
              ret.haj++;
              ret.kow++; break;
    case IYA: ret.yor++; ret.suk++; break;
    case AWA: ret.suk++;
              ret.yor++;
              ret.tak++;
              ret.odo++;
              ret.haj++; break;
    case TAK: ret.yas++; ret.awa++; break;
    case ODO: ret.yas++; ret.awa++; break;
    case HAJ: ret.yas++; ret.awa++; break;
    case YOR: ret.iya++; break;
    default: break;
  }
  return ret;
}
