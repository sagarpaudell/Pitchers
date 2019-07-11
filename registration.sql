-- phpMyAdmin SQL Dump
-- version 4.9.0.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Jul 11, 2019 at 10:25 AM
-- Server version: 10.3.15-MariaDB
-- PHP Version: 7.3.6

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `registration`
--

-- --------------------------------------------------------

--
-- Table structure for table `user`
--

CREATE TABLE `user` (
  `id` int(11) NOT NULL,
  `username` varchar(200) NOT NULL,
  `firstname` varchar(200) NOT NULL,
  `lastname` varchar(200) NOT NULL,
  `email` varchar(300) NOT NULL,
  `sex` varchar(50) NOT NULL,
  `pass` varchar(100) NOT NULL,
  `repass` varchar(200) NOT NULL,
  `nationality` varchar(100) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `user`
--

INSERT INTO `user` (`id`, `username`, `firstname`, `lastname`, `email`, `sex`, `pass`, `repass`, `nationality`) VALUES
(0, '', 'bajra', 'man', 'dwfdew', '', '121', '121', ''),
(0, '', 'joshi', 'guys', 's', '', '1', '1', ''),
(0, '', 'q', '1', 'q', '', 'q', 'q', ''),
(0, '', 'Bikesh', 'Bimali', 'bimalibikesh@gmail.com', '', 'bluerose7', 'bluerose7', ''),
(0, '', 'shreyam', 'pokhrel', '5', '', '5', '5', ''),
(0, 'RamrajCh', 'Ram', 'Raj', 'ch.ramraj35@gmail.com', 'male', 'ramraj@123', 'ramraj@123', ''),
(0, 'j', 'xyz', 'hh', 'l', 'male', '5', '5', ''),
(0, 'g', 'g', 'g', 'g', 'female', 'g', 'g', ''),
(0, '', 'g', '', '', 'female', '', '', ''),
(0, 'bishaljoshi08', 'bishal', 'joshi', 'abcd', 'female', 'abcd', 'abcd', ''),
(0, 'biraj11', 'biraj', 'adhikari', 'biraj@gmail.com', 'female', 'biraj11', 'biraj11', 'nepali');
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
