%{
figure; 
points = load('polinom.txt'); 
node_x = load('nodes_x.txt');
node_y = load('nodes_y.txt')
x = linspace(-5,2,1000)
y = 2.^x .* (x - 1).^2 - 2; 
hold on;
plot(x, y, 'black'); 

%
x1 = linspace(-5,2,1000)
y1 = -0.017 * x.^3.+0.025 * x.^2.-0.111 * x-1.885; 
hold on;
plot(x1, y1); 
hold on; 

plot(points(:, 1), points(:, 2), 'red');
hold on;
plot(node_x, node_y, 'or');
hold on;
grid on;

figure; 
f_err = load('differences.txt'); 
plot(f_err(:,1), f_err(:, 2));
grid on;

figure
max_err = load('max_err.txt');
max_err_dop = load('differences_dop.txt');
semilogy(max_err(:, 1), abs(max_err(:, 2)));
hold on;
semilogy(max_err(:, 1), abs(max_err_dop(:, 1)));
grid on;
%}

p1 = 0.97; p2 = -1.99; p3 = -3.97; p4 = -0.42;
figure;        
plot(p1, p2, 'ro'); 
hold on;
plot(p3, p4, 'ro'); 
x = linspace(-5,2,1000)
y = 2.^x .* (x - 1).^2 - 2; 
hold on;
plot(x, y, 'black'); 
y1 = -0.017*x.^3 +0.025*x.^2-0.111*x-1.885; 

plot(x, y1); 
hold on;
grid on;  

y1 = @(x) -0.016*x.^3 + 0.039*x.^2 - 0.108*x - 1.907;
x_value = -3.97;
result = y1(x_value);
disp(['y1 в ', num2str(x_value), '=' , num2str(result)]);

x_value2 = -1.5;
result2 = y1(x_value2);
disp(['y1 в ', num2str(x_value2), '=', num2str(result2)]);

y = @(x)2.^x .* (x - 1).^2 - 2; 
res = y(x_value);
disp(['y в ', num2str(x_value), '=' , num2str(res)]);
res1 = y(x_value2);
disp(['y в ', num2str(x_value2), '=' , num2str(res1)]);