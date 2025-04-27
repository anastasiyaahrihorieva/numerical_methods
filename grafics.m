figure; 
grafic = load('solutions.txt'); 
grafic2 = load('solutions2.txt');
x = 1:0.01:2;
plot(x, exp(x.^2) - x.^2 - 1);
hold on
plot(grafic(:,1), grafic(:,2), 'green');
hold on
plot(grafic(:,1), grafic(:,2), 'o');
hold on;
plot(grafic2(:,1), grafic2(:,2), 'red');
hold on
plot(grafic2(:,1), grafic2(:,2), 'o');
hold on
legend('точное', 'h1= 1/5=2h2', 'nodes h1' , 'h2=1/10', 'nodes h2');
title('решения');
xlabel('x');
ylabel('y');
grid on;

figure; 
grafic = load('errors.txt'); 
grafic2 = load('errors2.txt'); 
plot(grafic(:,1), grafic(:,2), 'red');
hold on;
plot(grafic(:,1), grafic(:,2), 'o');
hold on;
plot(grafic2(:,1), grafic2(:,2));
hold on
plot(grafic2(:,1), grafic2(:,2), 'o');
hold on
legend('h1','h1','h2', 'h2');
title('фактическая ошибка на интервале');
xlabel('x');
ylabel('фактическая ошибка');
grid on;



figure; 
grafic = load('eps_iter_data.txt'); 
loglog(grafic(:,1), grafic(:,3), 'red');
hold on;
loglog(grafic(:,1), grafic(:,1), 'black');
hold on;
title('фактическая ошибка от заданной точности');
legend('фактическая ошибка', 'заданная точность');
xlabel('заданная точность');
ylabel('фактическая ошибка');
grid on;


figure; 
grafic = load('eps_iter_data.txt'); 
semilogx(grafic(:,1), grafic(:,2));
hold on;
title('число итераций от заданной точности');
xlabel('заданная точность');
ylabel('число итераций');
grid on;


figure; 
grafic = load('length.txt'); 
loglog(grafic(:,1), grafic(:,2));
hold on;
loglog(grafic(:,1), grafic(:,1).^2);
hold on;
title('фактическая точность от величины шага');
ylabel('фактическая точность');
xlabel('величина шага');
grid on;