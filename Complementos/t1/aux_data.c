static bool bissexto(int a)
{
  return (a%4==0) && (a%400==0 || a%100!=0);
}

static int dias_no_ano(int ano)
{
  if (bissexto(ano)) return 366;
  return 365;
}

static int dias_no_mes(int mes, int ano)
{
  char dm[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (mes == 2 && bissexto(ano)) return 29;
  return dm[mes];
}

static int dias_desde_inicio_do_ano(int d, int m, int a)
{
  int dias;
  // já se passaram tantos dias desde o início do mês
  dias = d-1; // dia 1jan são 0 dias
  // soma o número de dias de cada mês anterior ao corrente
  while (m > 1) {
    m--;
    dias += dias_no_mes(m, a);
  }
  return dias;
}

static bool dt_data_ok(int d, int m, int a)
{
    if (d<1 || m<1 || m>12 || a<1582) return false;
    if (a == 1582 && (m<10 || (m==10 && d<15))) return false;
    if (d > dias_no_mes(m, a)) return false;
    return true;
}

