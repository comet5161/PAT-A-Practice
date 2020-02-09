main()
{
  int a,b;
  int l[10],n,n0;
  scanf("%d%d",&a,&b);
  a=a+b;
  l[0]=0;
  n=-1;
  if(a < 0)
  {
    printf("-");
    a=-a;
  }
  
  while(a>0)
  {
    l[++n]=a%1000;
    a/=1000;
  }
  n0=n;
  
  if(n>0)
  {
	  printf("%d,",l[n]);
	  n--;
  }
  while(n>0)
    printf("%3d,",l[n--]);

  if(n0>0)
	  printf("%3d",l[0]);
  else
	  printf("%d",l[0]);
  
  return 0;
}