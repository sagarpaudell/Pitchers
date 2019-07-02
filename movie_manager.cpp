#include "movie_manager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QDebug>
#include <QPixmap>
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
QList<QList<QVariant>> DbManager::getAlldrama(){
    QSqlQuery query("SELECT * FROM drama");
    int movieNameIndex = query.record().indexOf("moviename");
    int releaseDateIndex = query.record().indexOf("releassedate");
    int directorIndex = query.record().indexOf("director");
    int IMDBIndex = query.record().indexOf("IMDb");
    int castIndex = query.record().indexOf("cast");
    int synopsisIndex = query.record().indexOf("synopsis");
    //int imageIndex = query.record().indexOf("image");

    QList<QList<QVariant>> data;
    while (query.next()){
        QList<QVariant> list;

        QString movieName = query.value(movieNameIndex).toString();
        QString releaseDate = query.value(releaseDateIndex).toString();
        QString director = query.value(directorIndex).toString();
        QString IMDB = query.value(IMDBIndex).toString();
        QString cast = query.value(castIndex).toString();
        QString synopsis = query.value(synopsisIndex).toString();
       // QPixmap image= QPixmap();
        //image.loadFromData( query.value(imageIndex).toByteArray());

        //list.push_front(image);
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

    int movieNameIndex = query.record().indexOf("moviename");
    int releaseDateIndex = query.record().indexOf("releassedate");
    int directorIndex = query.record().indexOf("director");
    int IMDBIndex = query.record().indexOf("IMDb");
    int castIndex = query.record().indexOf("cast");
    int synopsisIndex = query.record().indexOf("synopsis");
    //int imageIndex = query.record().indexOf("image");

    QList<QList<QVariant>> data;
    while (query.next()){
        QList<QVariant> list;

        QString movieName = query.value(movieNameIndex).toString();
        QString releaseDate = query.value(releaseDateIndex).toString();
        QString director = query.value(directorIndex).toString();
        QString IMDB = query.value(IMDBIndex).toString();
        QString cast = query.value(castIndex).toString();
        QString synopsis = query.value(synopsisIndex).toString();
       // QPixmap image= QPixmap();
        //image.loadFromData( query.value(imageIndex).toByteArray());

        //list.push_front(image);
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

    QSqlQuery query("SELECT * FROM romance ");

    int movieNameIndex = query.record().indexOf("moviename");
    int releaseDateIndex = query.record().indexOf("releassedate");
    int directorIndex = query.record().indexOf("director");
    int IMDBIndex = query.record().indexOf("IMDb");
    int castIndex = query.record().indexOf("cast");
    int synopsisIndex = query.record().indexOf("synopsis");
    //int imageIndex = query.record().indexOf("image");

    QList<QList<QVariant>> data;
    while (query.next()){
        QList<QVariant> list;

        QString movieName = query.value(movieNameIndex).toString();
        QString releaseDate = query.value(releaseDateIndex).toString();
        QString director = query.value(directorIndex).toString();
        QString IMDB = query.value(IMDBIndex).toString();
        QString cast = query.value(castIndex).toString();
        QString synopsis = query.value(synopsisIndex).toString();
       // QPixmap image= QPixmap();
        //image.loadFromData( query.value(imageIndex).toByteArray());

        //list.push_front(image);
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

    int movieNameIndex = query.record().indexOf("moviename");
    int releaseDateIndex = query.record().indexOf("releassedate");
    int directorIndex = query.record().indexOf("director");
    int IMDBIndex = query.record().indexOf("IMDb");
    int castIndex = query.record().indexOf("cast");
    int synopsisIndex = query.record().indexOf("synopsis");
    //int imageIndex = query.record().indexOf("image");

    QList<QList<QVariant>> data;
    while (query.next()){
        QList<QVariant> list;

        QString movieName = query.value(movieNameIndex).toString();
        QString releaseDate = query.value(releaseDateIndex).toString();
        QString director = query.value(directorIndex).toString();
        QString IMDB = query.value(IMDBIndex).toString();
        QString cast = query.value(castIndex).toString();
        QString synopsis = query.value(synopsisIndex).toString();
       // QPixmap image= QPixmap();
        //image.loadFromData( query.value(imageIndex).toByteArray());

        //list.push_front(image);
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
    QSqlQuery query("SELECT title FROM imdb");
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

