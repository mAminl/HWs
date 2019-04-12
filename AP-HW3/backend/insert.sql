#insert accounts:
insert into "User" values (default, 'a1', '09120000001', 'a1@gmail.com',
 md5('11111'),'amin', 'amini', '1000', 'http//a1', now(), now());

insert into "User" values (default, 'a2', '09120000002', 'a2@gmail.com',
 md5('22222'),'ali', 'alavi', '1001', 'http//a2', now(), now());

insert into "User" values (default, 'a3', '09120000003', 'a3@gmail.com',
 md5('33333'),'reza', 'rezaei', '1002', 'http//a3', now(), now());

insert into "User" values (default, 'a4', '09120000004', 'a4@gmail.com',
 md5('44444'),'amir', 'amiri', '1003', 'http//a4', now(), now());

insert into "User" values (default, 'amir.jahanshahi', '09120000005', 'a5@gmail.com',
 md5('55555'),'hassan', 'hassani', '1004', 'http//a5', now(), now());

insert into "User" values (default, 'sHDiV4RHs', '09120000006', 'a6@gmail.com',
 md5('66666'),'hossein', 'hosseini', '1005', 'http//a6', now(), now());

insert into "User" values (default, 'a7', '09350000007', 'a7@gmail.com',
md5('77777'),'mohammad', 'mohammadi', '1007', 'http//a7', now(), now());

insert into "User" values (default, 'a8', '09350000008', 'a8@gmail.com',
 md5('88888'),'akbar', 'akbari', '1008', 'http//a8', now(), now());

insert into "User" values (default, 'a9', '09350000009', 'a9@gmail.com',
md5('99999'),'asghar', 'asghari', '1009', 'http//a9', now(), now());

insert into "User" values (default, 'a0', '09120000010', 'apstudent2019@gmail.com',
md5('00000'),'hamid', 'hamidi', '1010', 'http//a0', now(), now());

#insert Channels:
insert into "Channel" values (default, 'mathemathic', 'ch1',
 '', 1, now(), now());

insert into "Channel" values (default, 'sport', 'ch2',
 '', 2, now(), now());

insert into "Channel" values (default, 'chemistry', 'ch3',
 '', 3, now(), now());

insert into "Channel" values (default, 'movie', 'ch4',
 '', 4, now(), now());

insert into "Channel" values (default, 'astromy', 'ch5',
 '', 5, now(), now());

insert into "Channel" values (default, 'aut_ap_2019', 'ch6',
 '', 6, now(), now());

#insert membership:
insert into "ChannelMembership" values (1, 2, now());

insert into "ChannelMembership" values (2, 3, now());

insert into "ChannelMembership" values (3, 4, now());

insert into "ChannelMembership" values (4, 5, now());

insert into "ChannelMembership" values (5, 1, now());

insert into "ChannelMembership" values (6, 2, now());

insert into "ChannelMembership" values (7, 3, now());

insert into "ChannelMembership" values (8, 4, now());

insert into "ChannelMembership" values (9, 5, now());

insert into "ChannelMembership" values (10, 1, now());

insert into "ChannelMembership" values (3, 6, now());

insert into "ChannelMembership" values (6, 6, now());

insert into "ChannelMembership" values (10, 6, now());

insert into "ChannelMembership" values (5, 6, now());

#Blocked :|
insert into "BlockUser" values (1, 10, now());

insert into "BlockUser" values (2, 9, now());

insert into "BlockUser" values (2, 8, now());

#Messages:
insert into "Message" values (default, 5, 6, 'text', 
'hi', now(), now());

insert into "Message" values (default, 6, 5, 'text', 
'hi', now(), now());

insert into "Message" values (default, 5, 6, 'text', 
'how are you?', now(), now());

insert into "Message" values (default, 6, 5, 'text', 
'fine!thanks', now(), now());

insert into "Message" values (default, 5, 6, 'text', 
'how was collegue today?', now(), now());

insert into "Message" values (default, 6, 5, 'text', 
'good, many assigment', now(), now());

insert into "Message" values (default, 5, 6, 'text', 
'which course?', now(), now());

insert into "Message" values (default, 6, 5, 'text', 
'antenna and ap', now(), now());

insert into "Message" values (default, 5, 6, 'text', 
'nooooooooooo', now(), now());

insert into "Message" values (default, 6, 5, 'text', 
'please tell me antenna assigment', now(), now());

insert into "Message" values (default, 6, 5, 'image', 
' ', now(), now());

insert into "Message" values (default, 5, 6, 'video', 
'ok!,Bye!', now(), now());

insert into "Message" values (default, 6, 5, 'video', 
'Bye!', now(), now());