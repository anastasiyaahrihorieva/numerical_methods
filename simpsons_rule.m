figure
eps_runge = load('eps_runge.txt');
loglog(eps_runge(:,2),eps_runge(:,1));
hold on;
loglog(eps_runge(:,2),eps_runge(:,2)); 
hold on
legend ('фактическая ошибка от заданной точности', 'биссектриса')
xlabel('фактическая ошибка'); 
ylabel('заданная точность'); 
title ('фактическая ошибка от заданной точности по правилу Рунге')
grid on;

%{
figure
part_eps = load('eps_runge.txt');
semilogy(part_eps(:,3), part_eps(:,2));
xlabel ('число разбиений')
ylabel ('заданная точность')
grid on; 


figure
step_err = load('step_err.txt');
loglog(step_err(:,1), step_err(:,2));
hold on;
loglog(step_err(:,1), step_err(:,1).^4)
hold on;
xlabel ('длина интервала разбиения')
ylabel ('фактическая ошибка')
legend ('длина интервала разбиения от фактической ошибки', 'h^4')
grid on;
%}

%{
figure
eps_fact = load('fact_eps.txt');
%loglog(eps_fact(:,1), eps_fact(:,1));
%hold on;
loglog(eps_fact(:,2),eps_fact(:,1));
%hold on;
xlabel('фактическая ошибка');
grid on;
%}


%{
figure
eps_parts = load('parts_eps.txt');
semilogy(eps_parts(:,2), eps_parts(:,1));
xlabel ('число разбиений')
ylabel ('заданная точность')
grid on; 
%}

%{
figure
five_v = load('5v.txt');
loglog(five_v(:,1), five_v(:,2));
hold on
loglog(five_v(:,1), five_v(:,3));
hold on
xlabel ('длина отрезка')
ylabel ('фактическая точность')
legend ('длина интервала разбиения от фактической ошибки', 'h^3 от длины')
grid on;
%}