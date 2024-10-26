% PeaksLabel.m
 
Z=peaks(30); 
% Z: 30*30 double matrix;
% Look for the highest point;
 
zmax=max(Z);
Zmax=max(zmax);
% Firstly find the maximum of 30 columns,return zmax~1x30
% Secondly find the maximum of zmax, return 1x1
 
[Ymax, Xmax]=find(Z==Zmax);
% Y is first parameter using find()
 
zmin=min(Z);
Zmin=min(zmin);
[Ymin,Xmin]=find(Z==Zmin);
 
% plot func Z;
mesh(Z);hold on;
 
% label maximum and minimum point
plot3(Xmax,Ymax,Zmax,'k.','markersize',20);hold on
plot3(Xmin,Ymin,Zmin,'k.','markersize',20);hold on
 
text(Xmax,Ymax,Zmax,['max_value=',num2str(Zmax)])
text(Xmin,Ymin,Zmin, ['min_value=',num2str(Zmin)])