function az=mainfun(t,x)
u=3.*cos(t);
az=[0 1;-1 1]*x+[0;1]*u;
end