
Module: Maxymiser
Authors: 
- Jarrod Irwin <http://drupal.org/user/1370350>
- David Grayston <https://drupal.org/user/1710528>

Description
===========
Adds Maxymiser tag to your website.


Installation
============
* Copy the 'maxymiser' module directory in to your Drupal
sites/all/modules directory as usual.


Usage
=====
In the settings page enter your Maxymiser details.

All pages will now have the required JavaScript added to the
HTML header can confirm this by viewing the page source from
your browser.

Configuration
=============
The default is set to add the tracking tag to every page except the listed paths. By
default the following paths are listed for exclusion:

admin
admin/*
batch
node/add*
node/*/*
user/*/*

Tracking can also be excluded for specified roles. By default all roles will be tracked.

Sample Tag
==========
<script type="text/javascript" src="//service.maxymiser.net/cdn/<<YOUR SITE ID>>/js/mmcore.js"></script>
