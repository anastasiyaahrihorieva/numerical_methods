y = @(x)(x.^4 - 18*x.^3 - 10);
options = optimset('TolX', 1e-14);  
[x1,y1]=fzero(y, 18); 

root_alg = fzero(y, 18); 

[x2,y2]=fzero(y, 0);



y =@(x)(atan(x.^2 + 1./x) - x);
options = optimset('TolX', 1e-14); 
[x3,y3]=fzero(y, -1);
[x4,y4]=fzero(y, 1);

root_tran = fzero(y, 1);



% Инициализируйть массивы для хранения ошибок
pogresh = [0 0 0 0 0 0 0 0 0 0 0 0 0 0];
pogresh2 = [0 0 0 0 0 0 0 0 0 0 0 0 0 0];

figure % точность от итераций 
epsdata = load('data_algMPD.txt','-ascii'); 
epsdata2 = load('data_algNEW.txt','-ascii');

% точность от итераций алг
semilogx(epsdata(:,1), epsdata(:,3), 'red'); %график (координаты - матрица по х и у)
hold on; 
grid on;
semilogx(epsdata2(:,1), epsdata2(:,3), 'green');
hold on; 

% точность от итераций тран
epsdata = load('data_tranMPD.txt','-ascii');
hold on; 
epsdata2 = load('data_tranNEW.txt','-ascii');
hold on; 

% точность от итераций алг
semilogx(epsdata(:,1), epsdata(:,3), 'black');
semilogx(epsdata2(:,1), epsdata2(:,3), 'blue');
figure
epsdata = load('data_algMPD.txt','-ascii');
epsdata2 = load('data_algNEW.txt','-ascii');

% фактич от разн

%погреш алг
for i=1:14
     pogresh(i) =  abs(root_alg - epsdata(i,2));
     pogresh2(i) =  abs(root_alg - epsdata2(i,2));
 end

% график фактич от погреш алг
loglog(epsdata(:,1), pogresh, 'red');
hold on; 
loglog(epsdata2(:,1), pogresh2, 'green');
epsdata = load('data_tranMPD.txt','-ascii');
epsdata2 = load('data_tranNEW.txt','-ascii');

% погреш тран
for i=1:14
     pogresh(i) =  abs(root_tran - epsdata(i,2));
     pogresh2(i) =  abs(root_tran - epsdata2(i,2));
 end
%график фактич от погреш тран
loglog(epsdata(:,1), pogresh, 'black');
hold on; 
loglog(epsdata2(:,1), pogresh2, 'blue');
hold on;