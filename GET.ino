int GET() {
  messageIndex = gprs.isSMSunread();
  if (messageIndex > 0) { //At least, there is one UNREAD SMS
    gprs.readSMS(messageIndex, msg, MESSAGE_LENGTH, phone, datetime);
    gprs.deleteSMS(messageIndex);
    num = phone;
    if (num == vnum) {
      msg1 = msg;
      if (msg1 == "Stop") {
        digitalWrite(led, LOW);
        digitalWrite(buzz,LOW);
        GSM_stop=2;
      }
    }
  }
}
