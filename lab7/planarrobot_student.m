%clear
deg = pi/180;

L1 = 0.59;
L2 = 0.59;
L3 = 0.59;
L4 = 0.59;
L5 = 0.59;
lee = [L1, L2, L3, L4, L5];

L(1) = Revolute('d', 0, 'a', L1, 'alpha', 0, ...
    'I', [1, 1, 1], ...
    'm', 0.01, ...
    'Jm', 1, ...
    'G', 500, ...
    'B', 10e-4, ...
    'Tc', 10e-4, ...
    'qlim', [-2 2]);
% L(1).mdh=1;

L(2) = Revolute('d', 0, 'a', L2, 'alpha', 0, ...
    'I', [1, 1, 1], ...
    'm', 0.01, ...
    'Jm', 1, ...
    'G', 500, ...
    'B', 10e-4, ...
    'Tc', 10e-4, ...
    'qlim', [-2 2]);
% L(2).mdh=1;

L(3) = Revolute('d', 0, 'a', L3, 'alpha', 0, ...
    'I', [1, 1, 1], ...
    'm', 0.01, ...
    'Jm', 1, ...
    'G', 500, ...
    'B', 10e-4, ...
    'Tc', 10e-4, ...
    'qlim', [-2 2]);
% L(3).mdh=1; 

L(4) = Revolute('d', 0, 'a', L4, 'alpha', 0, ...
    'I', [1, 1, 1], ...
    'm', 0.01, ...
    'Jm', 1, ...
    'G', 500, ...
    'B', 10e-4, ...
    'Tc', 10e-4, ...
    'qlim', [-2 2]);
% L(4).mdh=1; 

L(5) = Revolute('d', 0, 'a', L5, 'alpha', 0, ...
    'I', [1, 1, 1], ...
    'm', 0.01, ...
    'Jm', 1, ...
    'G', 500, ...
    'B', 10e-4, ...
    'Tc', 10e-4, ...
    'qlim', [-2 2]);
% L(5).mdh=1; 


planar_robot = SerialLink (L,'name', 'planar_robot')
%planar_robot = SerialLink (L, 'name', 'Arm', ...
 %   'manufacturer', 'NU', 'ikine', 'puma', 'comment', 'no comment');

% planar_robot.model3d = 'planar_robot';
% 
%  home = [0 0 0 0 0]*deg;
% pose_end = planar_robot.fkine(home)
% 
clear L;
% 
% figure(1)
% 
%  planar_robot.plot(home)
% planar_robot.teach(home)
% 
% J=planar_robot.jacob0(home)
% T=((J')*[0 10 0 0 0 0]')
% gravload=planar_robot.gravload(home)
% Ttot=T+gravload'
% pose_end = planar_robot.fkine(home)
% xyz = transl(pose_end)
% rpy = tr2rpy(pose_end, 'deg')
% joints = planar_robot.getpos() %joint coordinates
% %Qtable max values Q-learning desired pose randomely select joint angles


