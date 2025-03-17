
figure; 
points = load('spline.txt'); 
nodes = load('nodes.txt'); 
plot(points(:, 1), points(:, 2), 'red');
hold on;
plot(nodes(:, 1), nodes(:, 2), 'o');
hold on;
x = linspace(-5,2,1000)
y = 2.^x .* (x - 1).^2 - 2; 
hold on;
plot(x, y, 'black');
grid on;

figure
x = linspace(-5,2,2000)
point_x = load('spline.txt');
difference = load('fact_err.txt');
plot(point_x(:, 1), difference(:, 1));
grid on;


figure
max_err = load('max_err.txt');
semilogy(max_err(:, 1), abs((max_err(:, 2))));
xlabel ("n");
ylabel ("max error");
grid on;


figure
change_interval = load("change_interval.txt");
semilogy(change_interval(:,1), abs(change_interval(:, 2)));
hold on
xlabel ("fdif2(a)");
ylabel ("max error");
grid on;
