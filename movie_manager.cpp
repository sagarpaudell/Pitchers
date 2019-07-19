#include "movie_manager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QDebug>
#include <QPixmap>
DbManager::DbManager(){}
DbManager::DbManager(const QString &path)
{
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setUserName("root");
    db.setPassword("");
    db.setDatabaseName(path);

    if (!db.open()){
        qDebug() << "Error: connection with database fail";
    }else{
        qDebug() << "Database: connection ok";
    }
}

DbManager::~DbManager()
{
    if (db.isOpen())
    {
        db.close();
    }
}

bool DbManager::isOpen() const
{
    return db.isOpen();
}
void setmovies();

QList<QList<QVariant>> DbManager::getAllmostrated(){
    QSqlQuery query("SELECT * FROM imdb");
    int movieNameIndex = query.record().indexOf("title");
    int releaseDateIndex = query.record().indexOf("year");
    int directorIndex = query.record().indexOf("director");
    int IMDBIndex = query.record().indexOf("imdb");
    int castIndex = query.record().indexOf("cast");
    int synopsisIndex = query.record().indexOf("synopsis");
    int imageIndex = query.record().indexOf("image");

    QList<QList<QVariant>> data;
    while (query.next()){
        QList<QVariant> list;

        QString movieName = query.value(movieNameIndex).toString();
        QString releaseDate = query.value(releaseDateIndex).toString();
        QString director = query.value(directorIndex).toString();
        QString IMDB = query.value(IMDBIndex).toString();
        QString cast = query.value(castIndex).toString();
        QString synopsis = query.value(synopsisIndex).toString();
        QPixmap image= QPixmap();
        image.loadFromData( query.value(imageIndex).toByteArray());

        list.push_front(image);
        list.push_front(synopsis);
        list.push_front(cast);
        list.push_front(IMDB);
        list.push_front(director);
        list.push_front(releaseDate);
        list.push_front(movieName);

        data.push_front(list);
    }
    return data;
}
QList<QVariant> DbManager::getmovies(QString name){
    QSqlQuery query("SELECT * FROM imdb SELECT * FROM imdb WHERE UPPER(REPLACE(title, ' ', '')) = UPPER(REPLACE(:moviename, ' ', ''))");
    query.bindValue ( ":moviename",name );
    int movieNameIndex = query.record().indexOf("title");
    int releaseDateIndex = query.record().indexOf("year");
    int directorIndex = query.record().indexOf("director");
    int IMDBIndex = query.record().indexOf("imdb");
    int castIndex = query.record().indexOf("cast");
    int synopsisIndex = query.record().indexOf("synopsis");
    int imageIndex = query.record().indexOf("image");

    QList<QVariant> data;
    while (query.next()){
        QList<QVariant> list;

        QString movieName = query.value(movieNameIndex).toString();
        QString releaseDate = query.value(releaseDateIndex).toString();
        QString director = query.value(directorIndex).toString();
        QString IMDB = query.value(IMDBIndex).toString();
        QString cast = query.value(castIndex).toString();
        QString synopsis = query.value(synopsisIndex).toString();
        QPixmap image= QPixmap();
        image.loadFromData( query.value(imageIndex).toByteArray());

        list.push_front(image);
        list.push_front(synopsis);
        list.push_front(cast);
        list.push_front(IMDB);
        list.push_front(director);
        list.push_front(releaseDate);
        list.push_front(movieName);

        data.push_front(list);
    }
    return data;
}
QList<QList<QVariant>> DbManager::getAllromance(){
    QSqlQuery query("SELECT * FROM romance");
    int movieNameIndex = query.record().indexOf("title");
    int releaseDateIndex = query.record().indexOf("year");
    int directorIndex = query.record().indexOf("director");
    int IMDBIndex = query.record().indexOf("imdb");
    int castIndex = query.record().indexOf("cast");
    int synopsisIndex = query.record().indexOf("synopsis");
    int imageIndex = query.record().indexOf("image");

    QList<QList<QVariant>> data;
    while (query.next()){
        QList<QVariant> list;

        QString movieName = query.value(movieNameIndex).toString();
        QString releaseDate = query.value(releaseDateIndex).toString();
        QString director = query.value(directorIndex).toString();
        QString IMDB = query.value(IMDBIndex).toString();
        QString cast = query.value(castIndex).toString();
        QString synopsis = query.value(synopsisIndex).toString();
        QPixmap image= QPixmap();
        image.loadFromData( query.value(imageIndex).toByteArray());

        list.push_front(image);
        list.push_front(synopsis);
        list.push_front(cast);
        list.push_front(IMDB);
        list.push_front(director);
        list.push_front(releaseDate);
        list.push_front(movieName);

        data.push_front(list);
    }
    return data;
}

QList<QList<QVariant>> DbManager::getAlldrama(){
    QSqlQuery query("SELECT * FROM drama");
    int movieNameIndex = query.record().indexOf("title");
    int releaseDateIndex = query.record().indexOf("year");
    int directorIndex = query.record().indexOf("director");
    int IMDBIndex = query.record().indexOf("imdb");
    int castIndex = query.record().indexOf("cast");
    int synopsisIndex = query.record().indexOf("synopsis");
    int imageIndex = query.record().indexOf("image");

    QList<QList<QVariant>> data;
    while (query.next()){
        QList<QVariant> list;

        QString movieName = query.value(movieNameIndex).toString();
        QString releaseDate = query.value(releaseDateIndex).toString();
        QString director = query.value(directorIndex).toString();
        QString IMDB = query.value(IMDBIndex).toString();
        QString cast = query.value(castIndex).toString();
        QString synopsis = query.value(synopsisIndex).toString();
        QPixmap image= QPixmap();
        image.loadFromData( query.value(imageIndex).toByteArray());

        list.push_front(image);
        list.push_front(synopsis);
        list.push_front(cast);
        list.push_front(IMDB);
        list.push_front(director);
        list.push_front(releaseDate);
        list.push_front(movieName);

        data.push_front(list);
    }
    return data;
}
QList<QList<QVariant>> DbManager::getAllcrime(){

    QSqlQuery query("SELECT * FROM crime ");

    int movieNameIndex = query.record().indexOf("title");
    int releaseDateIndex = query.record().indexOf("year");
    int directorIndex = query.record().indexOf("director");
    int IMDBIndex = query.record().indexOf("imdb");
    int castIndex = query.record().indexOf("cast");
    int synopsisIndex = query.record().indexOf("synopsis");
    int imageIndex = query.record().indexOf("image");

    QList<QList<QVariant>> data;
    while (query.next()){
        QList<QVariant> list;

        QString movieName = query.value(movieNameIndex).toString();
        QString releaseDate = query.value(releaseDateIndex).toString();
        QString director = query.value(directorIndex).toString();
        QString IMDB = query.value(IMDBIndex).toString();
        QString cast = query.value(castIndex).toString();
        QString synopsis = query.value(synopsisIndex).toString();
        QPixmap image= QPixmap();
        image.loadFromData( query.value(imageIndex).toByteArray());

        list.push_front(image);
        list.push_front(synopsis);
        list.push_front(cast);
        list.push_front(IMDB);
        list.push_front(director);
        list.push_front(releaseDate);
        list.push_front(movieName);

        data.push_front(list);
    }
    return data;
}
QList<QList<QVariant>> DbManager::getAlldocumentary(){

    QSqlQuery query("SELECT * FROM documentary ");

    int movieNameIndex = query.record().indexOf("title");
    int releaseDateIndex = query.record().indexOf("year");
    int directorIndex = query.record().indexOf("director");
    int IMDBIndex = query.record().indexOf("imdb");
    int castIndex = query.record().indexOf("cast");
    int synopsisIndex = query.record().indexOf("synopsis");
    int imageIndex = query.record().indexOf("image");

    QList<QList<QVariant>> data;
    while (query.next()){
        QList<QVariant> list;

        QString movieName = query.value(movieNameIndex).toString();
        QString releaseDate = query.value(releaseDateIndex).toString();
        QString director = query.value(directorIndex).toString();
        QString IMDB = query.value(IMDBIndex).toString();
        QString cast = query.value(castIndex).toString();
        QString synopsis = query.value(synopsisIndex).toString();
        QPixmap image= QPixmap();
        image.loadFromData( query.value(imageIndex).toByteArray());

        list.push_front(image);
        list.push_front(synopsis);
        list.push_front(cast);
        list.push_front(IMDB);
        list.push_front(director);
        list.push_front(releaseDate);
        list.push_front(movieName);

        data.push_front(list);
    }
    return data;
}
QStringList DbManager::getmoviesforsearch(){
    QSqlQuery query("SELECT title FROM imdb union (SELECT title FROM nepali )union(SELECT title FROM hindi)union (SELECT title FROM kids )union (SELECT title FROM southindian )");
    int movieNameIndex = query.record().indexOf("title");
    QStringList list;
    while (query.next()){

        QString movieName = query.value(movieNameIndex).toString();
        list.push_front(movieName);
    }
    return list;
}
//QList<QVariant> DbManager::display_search_details(const QString temp){
//    QSqlDatabase db;
//    db = QSqlDatabase::addDatabase("QMYSQL");
//    db.setHostName("127.0.0.1");
//    db.setUserName("root");
//    db.setPassword("");
//    db.setDatabaseName("movies");
//    if(db.open()){

//        //creating database queries
//      QSqlQuery query;
//      query.prepare ( "SELECT * FROM imdb WHERE UPPER(REPLACE(title, ' ', '')) = UPPER(REPLACE(:moviename, ' ', ''))");
//      query.bindValue ( ":moviename",temp );

//      //query.prepare(QString("SELECT * FROM drama WHERE  UPPER(REPLACE(moviename, ' ', '')) = UPPER(REPLACE(:moviename, ' ', '')) union (SELECT * FROM horror WHERE UPPER(REPLACE(moviename, ' ', '')) = UPPER(REPLACE(:moviename, ' ', ''))) union (SELECT * FROM romance WHERE UPPER(REPLACE(moviename, ' ', '')) = UPPER(REPLACE(:moviename, ' ', ''))) union (SELECT * FROM crime WHERE UPPER(REPLACE(moviename, ' ', '')) = UPPER(REPLACE(:moviename, ' ', ''))) "));
////      query.bindValue(":moviename",search_movie);


//      if(query.exec()){
//              qDebug() <<query.value(0)<<query.value(1)<<query.value(3)<<query.value(4)<<query.value(5)<<query.value(6);
//                     while (query.next()) {
//                         ui->movietitle->setText(query.value(1).toString());
//                         ui->year->setText(query.value(2).toString());
//                         ui->IMDb->setText(query.value(4).toString());
//                         ui->director->setText(query.value(3).toString());
//                         ui->cast->setText(query.value(5).toString());
//                         ui->synopsis->setText(query.value(6).toString());
//                         ui->genre->setText(query.value(7).toString());

//                         QPixmap outPixmap = QPixmap(); // Create QPixmap, which will be placed in picLabel
//                             /* Taking the image data from the table as QByteArray and put them in QPixmap
//                              * */
//                             outPixmap.loadFromData( query.value(8).toByteArray());
//                             ui->movie_poster->setPixmap(outPixmap.scaled(131,181));






//                     }
//       }
//      else{
////          QSqlQuery query1;
////          query1.prepare(QString("SELECT * FROM horror WHERE moviename = :moviename"));
////          query1.bindValue(":moviename",search_movie);
////          if(query1.exec()){
////                  qDebug() <<query1.value(0)<<query1.value(1)<<query1.value(3)<<query1.value(4)<<query1.value(5)<<query1.value(6);
////                         while (query1.next()) {
////                             ui->movietitle->setText(query1.value(0).toString());
////                             ui->year->setText(query1.value(1).toString());
////                             ui->IMDb->setText(query1.value(3).toString());
////                             ui->director->setText(query1.value(2).toString());
////                             ui->cast->setText(query1.value(4).toString());
////                             ui->synopsis->setText(query1.value(5).toString());
////                             //ui->IMDb->setText(query.value(3).toString());
////                         }
//         qDebug() << query.lastError().text();
//      }
//     db.close();
//    }
//    ui->stackedWidget->setCurrentIndex(7);

//}

QList<QList<QVariant>> DbManager::getAllnepali(){
    QSqlQuery query("SELECT * FROM nepali");
    int movieNameIndex = query.record().indexOf("title");
    int releaseDateIndex = query.record().indexOf("year");
    int directorIndex = query.record().indexOf("director");
    int IMDBIndex = query.record().indexOf("imdb");
    int castIndex = query.record().indexOf("cast");
    int synopsisIndex = query.record().indexOf("synopsis");
    int imageIndex = query.record().indexOf("image");

    QList<QList<QVariant>> data;
    while (query.next()){
        QList<QVariant> list;

        QString movieName = query.value(movieNameIndex).toString();
        QString releaseDate = query.value(releaseDateIndex).toString();
        QString director = query.value(directorIndex).toString();
        QString IMDB = query.value(IMDBIndex).toString();
        QString cast = query.value(castIndex).toString();
        QString synopsis = query.value(synopsisIndex).toString();
        QPixmap image= QPixmap();
        image.loadFromData( query.value(imageIndex).toByteArray());

        list.push_front(image);
        list.push_front(synopsis);
        list.push_front(cast);
        list.push_front(IMDB);
        list.push_front(director);
        list.push_front(releaseDate);
        list.push_front(movieName);

        data.push_front(list);
    }
    return data;
}
QList<QList<QVariant>> DbManager::getAllaction(){
    QSqlQuery query("SELECT * FROM action");
    int movieNameIndex = query.record().indexOf("title");
    int releaseDateIndex = query.record().indexOf("year");
    int directorIndex = query.record().indexOf("director");
    int IMDBIndex = query.record().indexOf("imdb");
    int castIndex = query.record().indexOf("cast");
    int synopsisIndex = query.record().indexOf("synopsis");
    int imageIndex = query.record().indexOf("image");

    QList<QList<QVariant>> data;
    while (query.next()){
        QList<QVariant> list;

        QString movieName = query.value(movieNameIndex).toString();
        QString releaseDate = query.value(releaseDateIndex).toString();
        QString director = query.value(directorIndex).toString();
        QString IMDB = query.value(IMDBIndex).toString();
        QString cast = query.value(castIndex).toString();
        QString synopsis = query.value(synopsisIndex).toString();
        QPixmap image= QPixmap();
        image.loadFromData( query.value(imageIndex).toByteArray());

        list.push_front(image);
        list.push_front(synopsis);
        list.push_front(cast);
        list.push_front(IMDB);
        list.push_front(director);
        list.push_front(releaseDate);
        list.push_front(movieName);

        data.push_front(list);
    }
    return data;
}
QList<QList<QVariant>> DbManager::getAllhistory(){
    QSqlQuery query("SELECT * FROM history");
    int movieNameIndex = query.record().indexOf("title");
    int releaseDateIndex = query.record().indexOf("year");
    int directorIndex = query.record().indexOf("director");
    int IMDBIndex = query.record().indexOf("imdb");
    int castIndex = query.record().indexOf("cast");
    int synopsisIndex = query.record().indexOf("synopsis");
    int imageIndex = query.record().indexOf("image");

    QList<QList<QVariant>> data;
    while (query.next()){
        QList<QVariant> list;

        QString movieName = query.value(movieNameIndex).toString();
        QString releaseDate = query.value(releaseDateIndex).toString();
        QString director = query.value(directorIndex).toString();
        QString IMDB = query.value(IMDBIndex).toString();
        QString cast = query.value(castIndex).toString();
        QString synopsis = query.value(synopsisIndex).toString();
        QPixmap image= QPixmap();
        image.loadFromData( query.value(imageIndex).toByteArray());

        list.push_front(image);
        list.push_front(synopsis);
        list.push_front(cast);
        list.push_front(IMDB);
        list.push_front(director);
        list.push_front(releaseDate);
        list.push_front(movieName);

        data.push_front(list);
    }
    return data;
}
QList<QList<QVariant>> DbManager::getAllhindi(){
    QSqlQuery query("SELECT * FROM hindi");
    int movieNameIndex = query.record().indexOf("title");
    int releaseDateIndex = query.record().indexOf("year");
    int directorIndex = query.record().indexOf("director");
    int IMDBIndex = query.record().indexOf("imdb");
    int castIndex = query.record().indexOf("cast");
    int synopsisIndex = query.record().indexOf("synopsis");
    int imageIndex = query.record().indexOf("image");

    QList<QList<QVariant>> data;
    while (query.next()){
        QList<QVariant> list;

        QString movieName = query.value(movieNameIndex).toString();
        QString releaseDate = query.value(releaseDateIndex).toString();
        QString director = query.value(directorIndex).toString();
        QString IMDB = query.value(IMDBIndex).toString();
        QString cast = query.value(castIndex).toString();
        QString synopsis = query.value(synopsisIndex).toString();
        QPixmap image= QPixmap();
        image.loadFromData( query.value(imageIndex).toByteArray());

        list.push_front(image);
        list.push_front(synopsis);
        list.push_front(cast);
        list.push_front(IMDB);
        list.push_front(director);
        list.push_front(releaseDate);
        list.push_front(movieName);

        data.push_front(list);
    }
    return data;
}
QList<QList<QVariant>> DbManager::getAllsouthindian(){
    QSqlQuery query("SELECT * FROM southindian");
    int movieNameIndex = query.record().indexOf("title");
    int releaseDateIndex = query.record().indexOf("year");
    int directorIndex = query.record().indexOf("director");
    int IMDBIndex = query.record().indexOf("imdb");
    int castIndex = query.record().indexOf("cast");
    int synopsisIndex = query.record().indexOf("synopsis");
    int imageIndex = query.record().indexOf("image");

    QList<QList<QVariant>> data;
    while (query.next()){
        QList<QVariant> list;

        QString movieName = query.value(movieNameIndex).toString();
        QString releaseDate = query.value(releaseDateIndex).toString();
        QString director = query.value(directorIndex).toString();
        QString IMDB = query.value(IMDBIndex).toString();
        QString cast = query.value(castIndex).toString();
        QString synopsis = query.value(synopsisIndex).toString();
        QPixmap image= QPixmap();
        image.loadFromData( query.value(imageIndex).toByteArray());

        list.push_front(image);
        list.push_front(synopsis);
        list.push_front(cast);
        list.push_front(IMDB);
        list.push_front(director);
        list.push_front(releaseDate);
        list.push_front(movieName);

        data.push_front(list);
    }
    return data;
}
QString give(){

}
void getusernationality(QString t){
    DbManager db("registration");
    QSqlQuery query("SELECT * FROM user WHERE username = :t");
    query.bindValue("t",t);
    int nationalityIndex = query.record().indexOf("nationality");
    QString nationality = query.value(nationalityIndex).toString();

}
QList<QString> DbManager::getUserInfo(const QString& uname) {
    QList<QString> userList;

    qDebug() << "users in db:";
    QSqlQuery query;
    query.prepare("SELECT * FROM user WHERE username = (:uname)");
    query.bindValue(":uname", uname);

    if(!query.exec()){
        qDebug()<<"Query err"<<query.lastError();
    }else{
        //Query was sucessful :)
        int email_id = query.record().indexOf("email");
        int fname_id = query.record().indexOf("firstname");
        int lname_id = query.record().indexOf("lastname");
        int sex_id = query.record().indexOf("sex");
        int pass_id = query.record().indexOf("pass");
        int nationality_id = query.record().indexOf("nationality");
        int age_id = query.record().indexOf("age");

        if(query.next()){
            QString email = query.value(email_id).toString();
            QString fname = query.value(fname_id).toString();
            QString lname = query.value(lname_id).toString();
            QString pass = query.value(pass_id).toString();
            QString nationality = query.value(nationality_id).toString();
            QString sex = query.value(sex_id).toString();
            QString age = query.value(age_id).toString();

            userList.push_front(age);
            userList.push_front(nationality);
            userList.push_front(sex);
            userList.push_front(pass);
            userList.push_front(email);
            userList.push_front(lname);
            userList.push_front(fname);

        }
    }

    return  userList;
}
QList<QList<QVariant>> DbManager::getAllanimated(){
    QSqlQuery query("SELECT * FROM kids");
    int movieNameIndex = query.record().indexOf("title");
    int releaseDateIndex = query.record().indexOf("year");
    int directorIndex = query.record().indexOf("director");
    int IMDBIndex = query.record().indexOf("imdb");
    int castIndex = query.record().indexOf("cast");
    int synopsisIndex = query.record().indexOf("synopsis");
    int imageIndex = query.record().indexOf("image");

    QList<QList<QVariant>> data;
    while (query.next()){
        QList<QVariant> list;

        QString movieName = query.value(movieNameIndex).toString();
        QString releaseDate = query.value(releaseDateIndex).toString();
        QString director = query.value(directorIndex).toString();
        QString IMDB = query.value(IMDBIndex).toString();
        QString cast = query.value(castIndex).toString();
        QString synopsis = query.value(synopsisIndex).toString();
        QPixmap image= QPixmap();
        image.loadFromData( query.value(imageIndex).toByteArray());

        list.push_front(image);
        list.push_front(synopsis);
        list.push_front(cast);
        list.push_front(IMDB);
        list.push_front(director);
        list.push_front(releaseDate);
        list.push_front(movieName);

        data.push_front(list);
    }
    return data;
}
bool DbManager::doesmovieExits(const QString &movieName) const{
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT title FROM imdb WHERE title = (:movieName)");
    checkQuery.bindValue(":movieName",movieName);
    if(checkQuery.exec()){
        if(checkQuery.next()){
            return true;
        }
    }else{
        qDebug()<<"does movie exist query failed "<<checkQuery.lastError();
    }
    return false;
}
bool DbManager::removemovie(const QString &movieName) const{
    bool success = false;

    if (doesmovieExits(movieName)){
        QSqlQuery queryDelete;
        queryDelete.prepare("DELETE FROM imdb WHERE title = (:movieName)");
        queryDelete.bindValue(":movieName", movieName);
        success = queryDelete.exec();
        if(!success){
            qDebug() << "remove  failed: " << queryDelete.lastError();
        }
    }else{
        qDebug() << "remove movies failed: item doesnt exist";
    }
    return success;
}
bool DbManager::doesuserExits(const QString &userName) const{
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT username FROM user WHERE username = (:userName)");
    checkQuery.bindValue(":userName",userName);
    if(checkQuery.exec()){
        if(checkQuery.next()){
            return true;
        }
    }else{
        qDebug()<<"does user exist query failed "<<checkQuery.lastError();
    }
    return false;
}
bool DbManager::removeuser(const QString &userName) const{
    bool success = false;

    if (doesmovieExits(userName)){
        QSqlQuery queryDelete;
        queryDelete.prepare("DELETE FROM user WHERE username = (:userName)");
        queryDelete.bindValue(":userName", userName);
        success = queryDelete.exec();
        if(!success){
            qDebug() << "remove  failed: " << queryDelete.lastError();
        }
    }else{
        qDebug() << "remove user failed: user doesnt exist";
    }
    return success;
}
