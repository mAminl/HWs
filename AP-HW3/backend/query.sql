#Q1:
select * from "User" where phone = '09120000001';
#Q2:
update "User" set email = 'apstudent2019@gmail.com'
 where phone = '09120000001';
#Q3:
select telegram_id from "Channel" where id in 
(select channel_id from "ChannelMembership" where user_id in 
(select id from "User" where phone = '09120000001'));
#Q4:
select count(*) from "User" where id in
(select user_id from "ChannelMembership" where channel_id in
(select id from "Channel" where telegram_id = 'aut_ap_2019'));
#Q5:
select email from "User" where phone like '0935%';
#Q6:
select phone from "User" where id in
(select blocked_user_id from "BlockUser" where blocker_user_id in
(select id from	"User" where phone = '09120000001'));
#Q7:
select phone from "User" where id in
(select blocked_user_id from "BlockUser" where blocker_user_id in
(select id from	"User" where phone = '09120000001') and
 ecreated_at > (now() - interval '1 month'));
#Q8:
select email from "User" where id in 
(select creator_id from "Channel" where id in 
(select channel_id from "ChannelMembership" where user_id in 
(select id from "User" where email = 'apstudent2019@gmail.com')
and  channel_id in
(select channel_id from
(select channel_id, count(user_id) from "ChannelMembership"
group by channel_id) as subq
where count > 3)));
#Q9:
select message_type, message_text from "Message" where
(sender_id = (select id from "User" where telegram_id = 'amir.jahanshahi')
and receiver_id = (select id from "User" where telegram_id ='sHDiV4RHs') or
(receiver_id = (select id from "User" where telegram_id = 'amir.jahanshahi')
and sender_id = (select id from "User" where telegram_id ='sHDiV4RHs')))
order by created_at desc limit 10;
#Q10:
select phone from "User" where id in 
(select creator_id from "Channel" where id in
(select channel_id from "ChannelMessage" where
updated_at in (select max from
(select max(updated_at) from
"ChannelMessage" group by channel_id) as subq
where max < (now() - interval'1 month'))));

#drop table "MessageAttachment","Message","GroupMessageAttachment","GroupMessage",
#"GroupMembership","Group","ChannelMessageAttachment","ChannelMessage","ChannelMembership" 
#,"Channel","BlockUser","User";
