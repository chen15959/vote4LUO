create database toupiao;
use toupiao;

/* drop table tbl_proxy */
create table tbl_proxy (
 proxy_str varchar(32) primary key,
 proxy_state int default 0,
 proxy_type int,
 test_time datetime default '1970-1-1',
 access_time datetime default '1970-1-1',
 fail_time datetime default '1970-1-1',
 fail_count int default 0,
 status_time datetime default '1970-1-1',
 status_count int default 0,
 vote_succeed_time datetime default '1970-1-1',
 vote_succeed_count int default 0,
 vote_refused_time datetime default '1970-1-1',
 vote_refused_count int default 0,

 dummy int
);


/* drop table tbl_proxy_history */
create table tbl_proxy_history (
 id int auto_increment primary key,
 proxy_str varchar(32),
 result int,
 begin_time datetime,
 end_time datetime
);
 
/* drop table tbl_user_agent */
create table tbl_user_agent (
 id int auto_increment primary key,
 user_agent varchar(320),
 last_time datetime default '1970-1-1'
);

insert into tbl_user_agent (user_agent) values ('Mozilla/5.0 (Windows NT 6.1; Win64; x64; rv:60.0) Gecko/20100101 Firefox/60.1');
insert into tbl_user_agent (user_agent) values ('Mozilla/5.0 (Windows NT 6.1; Win64; x64; rv:60.0) Gecko/20100101 Firefox/60.2');
insert into tbl_user_agent (user_agent) values ('Mozilla/5.0 (Windows NT 6.1; Win64; x64; rv:60.0) Gecko/20100101 Firefox/60.3');
insert into tbl_user_agent (user_agent) values ('Mozilla/5.0 (Windows NT 6.1; Win64; x64; rv:60.0) Gecko/20100101 Firefox/60.4');




/****************************************************************************************************/

create table tbl_browserinfo (
 headerstr varchar(4000),
 time1 datetime,
 keystr varchar(1000),
 valuestr varchar(3000)
);
 
 
 
 
create index idx_proxy_typ on tbl_proxy (typ);
 
 

create table tbl_status (
 tim datetime,
 g1 int,
 g2 int,
 g3 int,
 g4 int,
 g5 int,
 g6 int,
 g7 int,
 g8 int,
 g9 int,
 g10 int,
 g11 int,
 g12 int,
 g13 int,
 g14 int,
 g15 int,
 g16 int,
 g17 int,
 g18 int,
 g19 int,
 g20 int,
 g21 int,
 g22 int,
 g23 int,
 g24 int,
 g25 int,
 g26 int,
 g27 int,
 g28 int,
 g29 int,
 g30 int
);


