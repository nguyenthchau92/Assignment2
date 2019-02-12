/*==============================================================*/
/* DBMS name:      Microsoft SQL Server 2008                    */
/* Created on:     2/13/2019 2:03:10 AM                         */
/*==============================================================*/


if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('BILL') and o.name = 'FK_BILL_BILL_CASH_CASHIER')
alter table BILL
   drop constraint FK_BILL_BILL_CASH_CASHIER
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('BILL') and o.name = 'FK_BILL_CUSTOMER__CUSTOMER')
alter table BILL
   drop constraint FK_BILL_CUSTOMER__CUSTOMER
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('BUYING') and o.name = 'FK_BUYING_BUYING_SALER')
alter table BUYING
   drop constraint FK_BUYING_BUYING_SALER
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('BUYING') and o.name = 'FK_BUYING_BUYING2_CUSTOMER')
alter table BUYING
   drop constraint FK_BUYING_BUYING2_CUSTOMER
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('BUYING') and o.name = 'FK_BUYING_BUYING3_MOTOBIKE')
alter table BUYING
   drop constraint FK_BUYING_BUYING3_MOTOBIKE
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('CASHIER') and o.name = 'FK_CASHIER_INHERITAN_STAFF')
alter table CASHIER
   drop constraint FK_CASHIER_INHERITAN_STAFF
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('MAINTAINDATE') and o.name = 'FK_MAINTAIN_MAINTAIND_MOTOBIKE')
alter table MAINTAINDATE
   drop constraint FK_MAINTAIN_MAINTAIND_MOTOBIKE
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('MAINTAINDATE') and o.name = 'FK_MAINTAIN_MAINTAIND_CUSTOMER')
alter table MAINTAINDATE
   drop constraint FK_MAINTAIN_MAINTAIND_CUSTOMER
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('MAINTAINDATE') and o.name = 'FK_MAINTAIN_MAINTAIND_MECHANIS')
alter table MAINTAINDATE
   drop constraint FK_MAINTAIN_MAINTAIND_MECHANIS
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('MECHANISE') and o.name = 'FK_MECHANIS_INHERITAN_STAFF')
alter table MECHANISE
   drop constraint FK_MECHANIS_INHERITAN_STAFF
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('REGISTER') and o.name = 'FK_REGISTER_STAFF_REG_STAFF')
alter table REGISTER
   drop constraint FK_REGISTER_STAFF_REG_STAFF
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('SALER') and o.name = 'FK_SALER_INHERITAN_STAFF')
alter table SALER
   drop constraint FK_SALER_INHERITAN_STAFF
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('STAFF') and o.name = 'FK_STAFF_BRANCH_ST_BRANCH')
alter table STAFF
   drop constraint FK_STAFF_BRANCH_ST_BRANCH
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('STAFF') and o.name = 'FK_STAFF_MANAGER_STAFF')
alter table STAFF
   drop constraint FK_STAFF_MANAGER_STAFF
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('BILL')
            and   name  = 'BILL_CASHIER_FK'
            and   indid > 0
            and   indid < 255)
   drop index BILL.BILL_CASHIER_FK
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('BILL')
            and   name  = 'CUSTOMER_BILL_FK'
            and   indid > 0
            and   indid < 255)
   drop index BILL.CUSTOMER_BILL_FK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('BILL')
            and   type = 'U')
   drop table BILL
go

if exists (select 1
            from  sysobjects
           where  id = object_id('BRANCH')
            and   type = 'U')
   drop table BRANCH
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('BUYING')
            and   name  = 'BUYING_FK'
            and   indid > 0
            and   indid < 255)
   drop index BUYING.BUYING_FK
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('BUYING')
            and   name  = 'BUYING3_FK'
            and   indid > 0
            and   indid < 255)
   drop index BUYING.BUYING3_FK
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('BUYING')
            and   name  = 'BUYING2_FK'
            and   indid > 0
            and   indid < 255)
   drop index BUYING.BUYING2_FK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('BUYING')
            and   type = 'U')
   drop table BUYING
go

if exists (select 1
            from  sysobjects
           where  id = object_id('CASHIER')
            and   type = 'U')
   drop table CASHIER
go

if exists (select 1
            from  sysobjects
           where  id = object_id('CUSTOMER')
            and   type = 'U')
   drop table CUSTOMER
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('MAINTAINDATE')
            and   name  = 'MAINTAINDATE_FK'
            and   indid > 0
            and   indid < 255)
   drop index MAINTAINDATE.MAINTAINDATE_FK
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('MAINTAINDATE')
            and   name  = 'MAINTAINDATE3_FK'
            and   indid > 0
            and   indid < 255)
   drop index MAINTAINDATE.MAINTAINDATE3_FK
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('MAINTAINDATE')
            and   name  = 'MAINTAINDATE2_FK'
            and   indid > 0
            and   indid < 255)
   drop index MAINTAINDATE.MAINTAINDATE2_FK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('MAINTAINDATE')
            and   type = 'U')
   drop table MAINTAINDATE
go

if exists (select 1
            from  sysobjects
           where  id = object_id('MECHANISE')
            and   type = 'U')
   drop table MECHANISE
go

if exists (select 1
            from  sysobjects
           where  id = object_id('MOTOBIKE')
            and   type = 'U')
   drop table MOTOBIKE
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('REGISTER')
            and   name  = 'STAFF_REGISTER2_FK'
            and   indid > 0
            and   indid < 255)
   drop index REGISTER.STAFF_REGISTER2_FK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('REGISTER')
            and   type = 'U')
   drop table REGISTER
go

if exists (select 1
            from  sysobjects
           where  id = object_id('SALER')
            and   type = 'U')
   drop table SALER
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('STAFF')
            and   name  = 'BRANCH_STAFF_FK'
            and   indid > 0
            and   indid < 255)
   drop index STAFF.BRANCH_STAFF_FK
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('STAFF')
            and   name  = 'MANAGER_FK'
            and   indid > 0
            and   indid < 255)
   drop index STAFF.MANAGER_FK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('STAFF')
            and   type = 'U')
   drop table STAFF
go

/*==============================================================*/
/* Table: BILL                                                  */
/*==============================================================*/
create table BILL (
   BILLID               char(256)            not null,
   CUSTOMERID           char(11)             null,
   STAFFID              char(256)            not null,
   BILLPRICE            int                  null,
   constraint PK_BILL primary key nonclustered (BILLID)
)
go

/*==============================================================*/
/* Index: CUSTOMER_BILL_FK                                      */
/*==============================================================*/
create index CUSTOMER_BILL_FK on BILL (
CUSTOMERID ASC
)
go

/*==============================================================*/
/* Index: BILL_CASHIER_FK                                       */
/*==============================================================*/
create index BILL_CASHIER_FK on BILL (
STAFFID ASC
)
go

/*==============================================================*/
/* Table: BRANCH                                                */
/*==============================================================*/
create table BRANCH (
   BRANCHID             char(256)            not null,
   BRANCHNAME           char(256)            null,
   BRANCHLOCATION       char(255)            null,
   constraint PK_BRANCH primary key nonclustered (BRANCHID)
)
go

/*==============================================================*/
/* Table: BUYING                                                */
/*==============================================================*/
create table BUYING (
   STAFFID              char(256)            not null,
   CUSTOMERID           char(11)             not null,
   MOTOBIKEID           char(20)             not null,
   BUYDATE              datetime             null,
   constraint PK_BUYING primary key nonclustered (STAFFID, CUSTOMERID, MOTOBIKEID)
)
go

/*==============================================================*/
/* Index: BUYING2_FK                                            */
/*==============================================================*/
create index BUYING2_FK on BUYING (
CUSTOMERID ASC
)
go

/*==============================================================*/
/* Index: BUYING3_FK                                            */
/*==============================================================*/
create index BUYING3_FK on BUYING (
MOTOBIKEID ASC
)
go

/*==============================================================*/
/* Index: BUYING_FK                                             */
/*==============================================================*/
create index BUYING_FK on BUYING (
STAFFID ASC
)
go

/*==============================================================*/
/* Table: CASHIER                                               */
/*==============================================================*/
create table CASHIER (
   STAFFID              char(256)            not null,
   STA_STAFFID          char(256)            not null,
   BRANCHID             char(256)            not null,
   DATEOFBIRTH          datetime             null,
   NAMESTAFF            char(256)            null,
   SEX                  bit                  null,
   ADDRESS              char(256)            null,
   SALARY               int                  null,
   POSITION             char(256)            null,
   constraint PK_CASHIER primary key nonclustered (STAFFID)
)
go

/*==============================================================*/
/* Table: CUSTOMER                                              */
/*==============================================================*/
create table CUSTOMER (
   CUSTOMERID           char(11)             not null,
   CUSTOMERNAME         char(255)            null,
   CUSTOMERAGE          int                  null,
   CUSTOMERSEX          bit                  null,
   constraint PK_CUSTOMER primary key nonclustered (CUSTOMERID)
)
go

/*==============================================================*/
/* Table: MAINTAINDATE                                          */
/*==============================================================*/
create table MAINTAINDATE (
   STAFFID              char(256)            not null,
   CUSTOMERID           char(11)             not null,
   MOTOBIKEID           char(20)             not null,
   constraint PK_MAINTAINDATE primary key nonclustered (STAFFID, CUSTOMERID, MOTOBIKEID)
)
go

/*==============================================================*/
/* Index: MAINTAINDATE2_FK                                      */
/*==============================================================*/
create index MAINTAINDATE2_FK on MAINTAINDATE (
CUSTOMERID ASC
)
go

/*==============================================================*/
/* Index: MAINTAINDATE3_FK                                      */
/*==============================================================*/
create index MAINTAINDATE3_FK on MAINTAINDATE (
STAFFID ASC
)
go

/*==============================================================*/
/* Index: MAINTAINDATE_FK                                       */
/*==============================================================*/
create index MAINTAINDATE_FK on MAINTAINDATE (
MOTOBIKEID ASC
)
go

/*==============================================================*/
/* Table: MECHANISE                                             */
/*==============================================================*/
create table MECHANISE (
   STAFFID              char(256)            not null,
   STA_STAFFID          char(256)            not null,
   BRANCHID             char(256)            not null,
   DATEOFBIRTH          datetime             null,
   NAMESTAFF            char(256)            null,
   SEX                  bit                  null,
   ADDRESS              char(256)            null,
   SALARY               int                  null,
   POSITION             char(256)            null,
   constraint PK_MECHANISE primary key nonclustered (STAFFID)
)
go

/*==============================================================*/
/* Table: MOTOBIKE                                              */
/*==============================================================*/
create table MOTOBIKE (
   MOTOBIKEID           char(20)             not null,
   MOTOBIKETYPE         char(256)            not null,
   MOTOBIKECOLOR        char(256)            null,
   PRODUCER             char(256)            null,
   YEAR                 int                  null,
   constraint PK_MOTOBIKE primary key nonclustered (MOTOBIKEID)
)
go

/*==============================================================*/
/* Table: REGISTER                                              */
/*==============================================================*/
create table REGISTER (
   USERNAME             char(256)            not null,
   STAFFID              char(256)            null,
   PASSWORD             char(256)            null,
   constraint PK_REGISTER primary key nonclustered (USERNAME)
)
go

/*==============================================================*/
/* Index: STAFF_REGISTER2_FK                                    */
/*==============================================================*/
create index STAFF_REGISTER2_FK on REGISTER (
STAFFID ASC
)
go

/*==============================================================*/
/* Table: SALER                                                 */
/*==============================================================*/
create table SALER (
   STAFFID              char(256)            not null,
   STA_STAFFID          char(256)            not null,
   BRANCHID             char(256)            not null,
   DATEOFBIRTH          datetime             null,
   NAMESTAFF            char(256)            null,
   SEX                  bit                  null,
   ADDRESS              char(256)            null,
   SALARY               int                  null,
   POSITION             char(256)            null,
   constraint PK_SALER primary key nonclustered (STAFFID)
)
go

/*==============================================================*/
/* Table: STAFF                                                 */
/*==============================================================*/
create table STAFF (
   STAFFID              char(256)            not null,
   STA_STAFFID          char(256)            null,
   BRANCHID             char(256)            null,
   DATEOFBIRTH          datetime             null,
   NAMESTAFF            char(256)            null,
   SEX                  bit                  null,
   ADDRESS              char(256)            null,
   SALARY               int                  null,
   POSITION             char(256)            null,
   constraint PK_STAFF primary key nonclustered (STAFFID)
)
go

/*==============================================================*/
/* Index: MANAGER_FK                                            */
/*==============================================================*/
create index MANAGER_FK on STAFF (
STA_STAFFID ASC
)
go

/*==============================================================*/
/* Index: BRANCH_STAFF_FK                                       */
/*==============================================================*/
create index BRANCH_STAFF_FK on STAFF (
BRANCHID ASC
)
go

alter table BILL
   add constraint FK_BILL_BILL_CASH_CASHIER foreign key (STAFFID)
      references CASHIER (STAFFID)
go

alter table BILL
   add constraint FK_BILL_CUSTOMER__CUSTOMER foreign key (CUSTOMERID)
      references CUSTOMER (CUSTOMERID)
go

alter table BUYING
   add constraint FK_BUYING_BUYING_SALER foreign key (STAFFID)
      references SALER (STAFFID)
go

alter table BUYING
   add constraint FK_BUYING_BUYING2_CUSTOMER foreign key (CUSTOMERID)
      references CUSTOMER (CUSTOMERID)
go

alter table BUYING
   add constraint FK_BUYING_BUYING3_MOTOBIKE foreign key (MOTOBIKEID)
      references MOTOBIKE (MOTOBIKEID)
go

alter table CASHIER
   add constraint FK_CASHIER_INHERITAN_STAFF foreign key (STAFFID)
      references STAFF (STAFFID)
go

alter table MAINTAINDATE
   add constraint FK_MAINTAIN_MAINTAIND_MOTOBIKE foreign key (MOTOBIKEID)
      references MOTOBIKE (MOTOBIKEID)
go

alter table MAINTAINDATE
   add constraint FK_MAINTAIN_MAINTAIND_CUSTOMER foreign key (CUSTOMERID)
      references CUSTOMER (CUSTOMERID)
go

alter table MAINTAINDATE
   add constraint FK_MAINTAIN_MAINTAIND_MECHANIS foreign key (STAFFID)
      references MECHANISE (STAFFID)
go

alter table MECHANISE
   add constraint FK_MECHANIS_INHERITAN_STAFF foreign key (STAFFID)
      references STAFF (STAFFID)
go

alter table REGISTER
   add constraint FK_REGISTER_STAFF_REG_STAFF foreign key (STAFFID)
      references STAFF (STAFFID)
go

alter table SALER
   add constraint FK_SALER_INHERITAN_STAFF foreign key (STAFFID)
      references STAFF (STAFFID)
go

alter table STAFF
   add constraint FK_STAFF_BRANCH_ST_BRANCH foreign key (BRANCHID)
      references BRANCH (BRANCHID)
go

alter table STAFF
   add constraint FK_STAFF_MANAGER_STAFF foreign key (STA_STAFFID)
      references STAFF (STAFFID)
go

